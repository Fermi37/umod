/*
 * ____________________________________________________________/\\\__        
 *  ___________________________________________________________\/\\\__       
 *   ___________________________________________________________\/\\\__      
 *    __/\\\____/\\\_____/\\\\\__/\\\\\________/\\\\\____________\/\\\__     
 *     _\/\\\___\/\\\___/\\\///\\\\\///\\\____/\\\///\\\_____/\\\\\\\\\__    
 *      _\/\\\___\/\\\__\/\\\_\//\\\__\/\\\___/\\\__\//\\\___/\\\////\\\__   
 *       _\/\\\___\/\\\__\/\\\__\/\\\__\/\\\__\//\\\__/\\\___\/\\\__\/\\\__  
 *        _\//\\\\\\\\\___\/\\\__\/\\\__\/\\\___\///\\\\\/____\//\\\\\\\/\\_ 
 *         __\/////////____\///___\///___\///______\/////_______\///////\//__
 * 
 * umod -- Minimalistic finite element modeling
 *
 * copyright (c) Csirik Mihaly (csirik@gmail.com)
 *
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "umod.h"


int main( int argc, char **argv, char **envp )
{
    struct umod_mesh_s ellshaped;
    umod_mesh_lshaped( 1, 1, .1, &ellshaped );
    umod_mesh_output( "ellshaped", &ellshaped );
    umod_mesh_free( &ellshaped );

    return 0;
}
