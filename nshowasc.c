
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATH_MAX 250
#include <ncurses.h>
#include "../lib/libncurse.c"

//  apt-get install  rxvt-unicode 

int charcode = 1;


void drawtable( int pagego )
{
     int rows, cols;  
     int ci, posx, posy ;  
     getmaxyx( stdscr, rows, cols);

         erase();  
         posx = 1 ; posy = 3;
         mvprintw( 0, 0, "ASCII CHART" );
         mvprintw( 1, 0, "-----------" );

         for( ci = 40 ; (ci <= 300) ; ci++ )
         {
            mvprintw( posy , posx , "%c", ci );
            posx = posx +2 ; 

            if ( posx >= cols - 10 ) 
            {
                posy++; posx = 1 ; 
            }
         }
          
         mvprintw(rows-1 , 0, "<Press Key to Continue (hjkl)>");
}


void drawit( int pagego )
{
     int rows, cols;  
     getmaxyx( stdscr, rows, cols);
     mvprintw(5 , 5, "NSHOWASC (ASCII) !!!");	
     if ( pagego >= 1 ) mvprintw(7 , 5, "INFO KEY: %d-DEC" , pagego );
      
     if ( pagego == 'j' ) charcode++;
     else if ( pagego == 'k' ) charcode--;

     mvprintw( 6 , 5, "CODE: %d", charcode );

     mvprintw( 10 , 5, "|" );
     addch(  charcode );
     printw( "|" );

     mvprintw( 12 , 5, "|" );
     printw( "%c", charcode );
     printw( "|" );

     mvprintw(rows-1 , 0, "<Press Key to Continue (hjkl)>");

}



int main()
{	
        int ch ;  int gameover = 0;
	initscr();			/* Start curses mode 		  */
        curs_set( 0 );

        char charo[PATH_MAX]; 
        int fooint ; 

        erase(); ch = 0 ; 
        drawit( 0 );

        while( gameover == 0 )
        {
	  ch = getch();			/* Wait for user input */
          if ( ch == 't' )
            drawtable( ch );
          else
          {
            erase();
            drawit( ch );
          }
        }

        curs_set( 1 );
	endwin();			/* End curses mode		  */
	return 0;
}


