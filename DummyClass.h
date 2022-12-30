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


#ifndef  DUMMYCLASS_INC
#define  DUMMYCLASS_INC

#include <stdlib.h>

typedef struct
{
   int some_var;
} DummyClass;

DummyClass* DummyClass_New();
void DummyClass_Delete( DummyClass** d );
void DummyClass_Print( DummyClass* d );
void DummyClass_Set( DummyClass* d, int new_val );
int DummyClass_Get( DummyClass* d );

#endif   /* ----- #ifndef DUMMYCLASS_INC  ----- */
