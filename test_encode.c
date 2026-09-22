/*
Name: Deepak Kumar Singh
Date:28/07/2026
Description : Steganography
Input:./a.out -e beautiful.bmp secret.txt stego.bmp
Output:

Lets see what have you selected !!!
Congrats! You have selected encoding
Received a proper bmp file
Received proper txt file 
Received the output file name
Read and validated encode arguments successfully
<---------Lets start encoding--------->
Lets open the files in required mode successfully
Opened required files in required mode successfully
Check if beautiful.bmp file is suitable for encoding
width = 1024
height = 768
Yes, beautiful.bmp file is suitable for encoding
Copying the header from beautiful.bmp to stego.bmp as it is
Done, Copied!!
Started to encode magic string
Done. Completed encoding magic string
Encoded secret file exten size successfully
Encoded secret file extension successfully
Encoded secret file size successfully
Encoded secert file data successfully
Copied remaining data successfully
Completed encoding successfully

Open files successfully
Magic string decoded successfully
File extension size decoded successfully
Secret file extension decoded successfully
Secret file size decoded successfully
Secret file data decoded successfully
<---------Completed decoding--------->
*/
#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "common.h"
#include "decode.h"

/* Function prototype */
OperationType check_operation_type(char *argv[]);

int main(int argc, char **argv)
{
    /* Argument validation */
    if(argc < 3)
    {
        printf("Invalid input\n");
        printf("Usage:\n");
        printf("Encoding : ./a.out -e beautiful.bmp secret.txt stego.bmp\n");
        printf("Decoding : ./a.out -d stego.bmp decode.txt\n");
        return e_failure;
    }

    printf("Lets see what have you selected !!!\n");

    OperationType operation = check_operation_type(argv);

    if(operation == e_encode)
    {
        printf("Congrats! You have selected encoding\n");

        EncodeInfo steganography;

        if(read_and_validate_encode_args(argv, &steganography) == e_success)
        {
            printf("Read and validated encode arguments successfully\n");
            printf("<---------Lets start encoding--------->\n");

            if(do_encoding(&steganography) == e_success)
            {
                printf("Completed encoding successfully\n");
            }
            else
            {
                printf("Failed to perform encoding\n");
                return e_failure;
            }
        }
        else
        {
            printf("Failed to validate encode arguments\n");
            return e_failure;
        }
    }
    else if(operation == e_decode)
    {
        printf("Congrats! You have selected decoding\n");

        DecodeInfo decInfo;

        if(read_and_validate_decode_args(argv, &decInfo) == d_success)
        {
            printf("Read and validated decode arguments successfully\n");
            printf("############### Started Decoding ##############\n");

            if(do_decoding(&decInfo) == d_success)
            {
                printf("<---------Completed decoding--------->\n");
            }
            else
            {
                printf("Failed to perform decoding\n");
                return e_failure;
            }
        }
        else
        {
            printf("Failed to validate decode arguments\n");
            return e_failure;
        }
    }
    else
    {
        printf("Invalid option\n");
        printf("Please pass:\n");
        printf("Encoding : ./a.out -e beautiful.bmp secret.txt stego.bmp\n");
        printf("Decoding : ./a.out -d stego.bmp decode.txt\n");
        return e_failure;
    }

    return e_success;
}


/* Function definition */
OperationType check_operation_type(char *argv[])
{
    if(strcmp(argv[1], "-e") == 0)
    {
        return e_encode;
    }
    else if(strcmp(argv[1], "-d") == 0)
    {
        return e_decode;
    }
    else
    {
        return e_unsupported;
    }
}