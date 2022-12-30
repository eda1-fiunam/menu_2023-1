/* Copyright (C) 
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 * 2022 - francisco dot rodriguez at ingenieria dot unam dot edu
 */


#include "Menu.h"

static void print_menu_title( Menu* menu )
{
   size_t len = strlen( menu->title );

   printf( "\n" );

   for( size_t i = 0; i < len + 2; ++i )
   {
      printf( "=" );
   }

   printf( "\n %s\n", menu->title );

   for( size_t i = 0; i < len + 2; ++i )
   {
      printf( "=" );
   }

   printf( "\n" );
}


Menu* Menu_New( MenuEntry* options, size_t num_options, char* title )
{
   Menu* m = malloc( sizeof( Menu ) );
   if( m )
   {
      m->options = options;
      m->num_options = num_options;
      m->title = title;
   }

   return m;
}


void Menu_Delete( Menu** menu )
{
   assert( menu );
   assert( *menu );

   free( *menu );
   *menu = NULL;
}
 


int Menu_Run( Menu* menu )
{
   assert( menu );

   while( 1 )
   {
      int option = Menu_Show( menu );

      if( option == 0 || menu->options[ option ].action == NULL )
      {
         return 0;
      }
      else
      {
         return menu->options[ option ].action( menu->options[ option ].params );
      }

      // también funciona:

      /*
      return ( option == 0 || menu->options[ option ].action == NULL )
         ? 0
         : menu->options[ option ].action( menu->options[ option ].params );
      */
      
      // ... pero dificulta la depuración (en caso de que quisieran o necesitaran realizarla)
   }
}



void Menu_Set( Menu* menu, MenuEntry* options, size_t num_options, char* title )
{
   menu->options = options;
   menu->num_options = num_options;
   menu->title = title;
}

int Menu_Show( Menu* menu )
{
   size_t option = 0;

   while( 1 )
   {
      print_menu_title( menu );

      for( size_t i = 0; i < menu->num_options; ++i )
      {
         printf( "%ld) %s\n", i, menu->options[ i ].text );
      }

      printf( "\n? " );
      // este "prompt" lo pueden modificar como quieran

      scanf( "%ld", &option );

#if 0 
      if( 0 <= option && option < menu->num_options )
      {
         int ret_val = 0;

         if( menu->options[ option ].action != NULL )
         {
            ret_val = menu->options[ option ].action( menu->options[ option ].params );
         }

         return ret_val;
      }
#endif  

      if( 0 <= option && option < menu->num_options )
      {
         return option;
      }

      printf( "Opción no válida\n" );
   }
}

void Menu_Set_Title( Menu* menu, char* title )
{
   menu->title = title;
}
