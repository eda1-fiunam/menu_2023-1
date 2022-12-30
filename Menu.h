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

#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


/**
 * @brief Firma de las funciones que realizarán una acción.
 *
 */
typedef int (*MenuAction)( void* );


/**
 * @brief Define cada entrada del menú.
 */
typedef struct 
{
   char       text[ 80 ]; /**< Texto del menú */
   MenuAction action;     /**< Acción a realizar cuando se escoja esta entrada @see MenuAction */
   void*      params;     /**< Parámetro opcional (genérico) */
} MenuEntry;

/**
 * @brief Clase Menú.
 */
typedef struct
{
   MenuEntry* options;     /**< Arreglo de entradas del menú. @see MenuEntry */
   size_t     num_options; /**< Es el número de entradas del menú */
   char*      title;       /**< Título del menú para imprimir */
} Menu;


/**
 * @brief Crea un nuevo menú.
 *
 * @param options Arreglo con las opciones del menú. @see MenuEntry
 * @param num_options Número de opciones del menú, incluyendo la opción de salida (siempre es la 0)
 * @param title Título del menú.
 *
 * @return Un nuevo objeto Menu
 */
Menu* Menu_New( MenuEntry* options, size_t num_options, char* title );

/**
 * @brief Destruye a un objeto Menu.
 *
 * @param menu Objeto Menu a destruir.
 */
void Menu_Delete( Menu** menu );

int Menu_Run( Menu* menu );

/**
 * @brief Muestra el menú en la pantalla.
 *
 * @param menu Un objeto Menu.
 *
 * @return La opción que el usuario escogió.
 */
int Menu_Show( Menu* menu );


#endif  // MENU_H
