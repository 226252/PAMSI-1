/************************************************************************************    
*    Made by  226262 Wrocław University of Technology                               *                
*                                                                                   *                        
*    This program is free software; you can redistribute it and/or modify           *            
*    it under the terms of the GNU General Public License as published by           *        
*    the Free Software Foundation; either version 2 of the License, or              *            
*    (at your option) any later version.                                            *            
*                                                                                   *
*    This program is distributed in the hope that it will be useful,                *            
*    but WITHOUT ANY WARRANTY; without even the implied warranty of                 *            
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                  *        
*    GNU General Public License for more details.                                   *        
*                                                                                   *        
*    You should have received a copy of the GNU General Public License              *                    
*    along with this program; if not, write to the Free Software                    *        
*    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA     *    
*                                                                                   *        
*************************************************************************************/
#include<iostream>
#include<fstream>
#include<cstdlib>
#include"../inc/array.h"
#include"../inc/irunnable.h"
#include"../inc/timer.h"
#include"../inc/list.h"
#include "../inc/stack.h"

//*********************************************************//
int main(int argc, char *argv[]){


    timer STOPEREK;
    stru::array<int> tablica;
    
    stru::stack<int> stosik;

    stosik.push(1);
    stosik.print();
    stosik.push(2);
    stosik.print();
    

    
    return 0;
}
