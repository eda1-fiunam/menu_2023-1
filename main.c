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

/*
 * El ejemplo original se compila así:
 *
 * $ gcc -Wall -std=c99 -osalida.out main.c DummyClass.c Menu.c submenu1.c -g
 *
 */

#include <stdio.h>

#include "Menu.h"
#include "DummyClass.h"

#include "submenu1.h"
// la opción delete_product manda llamar a este submenu



int print_stock( void* params )
{
   DummyClass* dummy_object = (DummyClass*) params;

   printf( "print_stock()\n" );
   DummyClass_Print( dummy_object );


   return 1;
   // puedes devolver lo que sea más conveniente a tu aplicación
}

int insert_product( void* params )
{
   DummyClass* dummy_object = (DummyClass*) params;

   printf( "insert_product(): %d\n", DummyClass_Get( dummy_object ) );

   int cont = DummyClass_Get( dummy_object );
   ++cont;
   DummyClass_Set( dummy_object, cont );

   return 2;
}

int delete_product( void* params )
{
   DummyClass* dummy_object = (DummyClass*) params;

   printf( "delete_product(): %d\n", DummyClass_Get( dummy_object ) );

   // llama a un submenú:
   int salir = 0;
   do
   {
      salir = submenu1( dummy_object );
   } while( salir != 0 );

   return 3;
}


#define MAIN_MENU_OPTIONS 4

int main_menu( DummyClass* obj )
{
   /*
    * Observa que print_stock, insert_product y delete_product NO son objetos, son funciones 
    * que a su vez llamarían a las funciones del tipo abstracto (clase) correspondiente.
    */
   MenuEntry main_menu_entries[ MAIN_MENU_OPTIONS ] =
   {
      { "Salir", NULL },      // la primer opción siempre es Salir/NULL

      { 
         "Ver el inventario", // Texto para mostrar
         print_stock,         // Callback (función que realiza el trabajo). Siempre debe ser int f(void*)
         (void*)obj           // le pasamos al objeto |obj| del tipo DummyClass
      },

      { "Insertar un producto", insert_product, (void*)obj },
      { "Eliminar un producto", delete_product, (void*)obj },
   };

   Menu* menu = Menu_New( main_menu_entries, MAIN_MENU_OPTIONS, "MENÚ PRINCIPAL" );

   int ret_val = Menu_Run( menu );

   Menu_Delete( &menu );

   return ret_val;
   // puedes devolver lo que sea más conveniente a tu aplicación
}


int main()
{
   DummyClass* an_object = DummyClass_New();
   // creamos al objeto principal de la aplicación

   do{;}while( main_menu( an_object ) != 0 );
   // inicia el procesamiento de los menús y le pasamos al objeto principal

   // también funciona:
   /*
   while( main_menu( an_object ) != 0 )
   {
      ;
   }
   */

   DummyClass_Delete( &an_object );
}
