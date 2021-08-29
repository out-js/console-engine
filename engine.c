#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

// extern unsigned char width = 10, height = 10 ; 
// #define xlen width
// #define ylen height
// const unsigned char XLENGTH = 10, YLENGTH = 10;
#define XLENGTH 10
#define YLENGTH 10
static char a [ XLENGTH ][ YLENGTH ];
//static char MAPSFILE = "maps/";

// void createArea ( ) 
// {
//     extern const unsigned char XLENGTH = width,YLENGTH = height;
//     return;
// }

char * strip ( char *str ) 
{
    char *nStr = malloc (sizeof (char));

    for ( unsigned int i = 0; i < sizeof str ; i++ )
    {
        if ( str [i] == ' ' || str [i] == '\n' )
        {
            continue;
        }
        else
        {
            for ( unsigned int z = ( sizeof str) - 2; z >= 0; z-- )
            {
                if ( str [z] == ' ' || str [z] == '\n' )
                {
                    continue;
                }
                else
                {
                    for ( unsigned int j = i, k = 0; j <= z; j++, k++ )
                    {
                        printf ( "%d%d\n", j , k );
                        nStr [k] = str[j];
                    }
                    return ( nStr );
                }
            }
        }
    }
}

unsigned char setTimeout ( unsigned int sec ) 
{
    time_t startT, currentT;
    startT = time(NULL);

    while ( true )
    {
        currentT = time(NULL);
        if ( currentT - startT == sec ) {
            return 0;
        }
    }
}

void printArea ( ) 
{
    for ( unsigned char x = XLENGTH ; x > 0 ; x-- )
    {
        for ( unsigned char y = YLENGTH ; y > 0 ; y-- )
        {
            if ( a [ x ][ y ] )
            {
                printf( "#" );
            }
        }
        printf( "\n" );
    }
    return;
}

void draw () 
{
    char mode[100];

    while ( true ) 
    {
        printf ( "Enter a figure, or print \"help\" to take help :)  :" );
        scanf ( "%s" , mode );
        // mode = strip ( mode );
        printf ("\n%s\n", strip (mode) );
        if ( mode == "r" )
        {
            unsigned char height, width;

            printf ( "Enter a width and height in format: \"10 10\"\n" );
            scanf ( "%n %s", &width, &height );

        }
        if ( mode == "exit" )
        {
            return;
        }
        else
        {
            printf ( "Incorrect input, try again.\n" );
        }
    }
}

int main () 
{
    draw ();
    // while ( true )
    // {
    //     printArea ( );
    //     setTimeout( 1 );
    // }
}

