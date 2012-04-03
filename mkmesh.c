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
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define REAL double
#include "triangle.h"

#include "umod.h"

void umod_mesh_free( struct umod_mesh_s *mesh )
{
    free( mesh->verts );
    free( mesh->tris );
}

void umod_mesh_output( const char *name, struct umod_mesh_s *mesh )
{
    FILE *f;
    size_t i;
    char node_filename[64], ele_filename[64];

    snprintf( node_filename, sizeof(node_filename), "%s.node", name );
    snprintf( ele_filename, sizeof(ele_filename), "%s.ele", name );

    if( ( f = fopen( node_filename, "w" ) ) == NULL )
    {
	perror("Failed to open node file for writing");
	exit( EXIT_FAILURE );
    }

    fprintf( f, "%zu 2 0 0\n", mesh->num_verts );

    for( i = 0; i < mesh->num_verts; ++i )
    {
	fprintf( f, "%zu %f %f\n", i, mesh->verts[ 2*i ], mesh->verts[ 2*i + 1 ] );
    }

    fclose( f );

    if( ( f = fopen( ele_filename, "w" ) ) == NULL )
    {
	perror("Failed to open ele file for writing");
	exit( EXIT_FAILURE );
    }

    fprintf( f, "%zu 3 0\n", mesh->num_tris );

    for( i = 0; i < mesh->num_tris; ++i )
    {
	fprintf( f, "%zu %d %d %d\n", i, mesh->tris[ 3*i ], mesh->tris[ 3*i + 1 ], mesh->tris[ 3*i + 2 ] );
    }

    fclose( f );
}

/* Make an L-shaped domain */
void umod_mesh_lshaped( double dx, double dy, double maxarea, struct umod_mesh_s *mesh )
{
    struct triangulateio input, output;
    char options[32];

    /* Initialize input buffer */
    memset( &input, 0, sizeof( input ) );

    input.numberofpoints = 6;
    input.numberofsegments = 6;

    input.regionlist = NULL;
    input.pointmarkerlist = NULL;
    
    input.pointlist = malloc( sizeof( *input.pointlist ) * 2 * input.numberofpoints );

    input.pointlist[0] = 0.0;        input.pointlist[1] = 0.0;
    input.pointlist[2] = dx;         input.pointlist[3] = 0.0;
    input.pointlist[4] = dx;         input.pointlist[5] = 0.5*dy;
    input.pointlist[6] = 0.5*dx;     input.pointlist[7] = 0.5*dy;
    input.pointlist[8] = 0.5*dx;     input.pointlist[9] = dy;
    input.pointlist[10] = 0;         input.pointlist[11] = dy;

    input.segmentlist = malloc( sizeof( *input.segmentlist ) * 2 * input.numberofsegments );

    input.segmentlist[0] = 0;    input.segmentlist[1] = 1;
    input.segmentlist[2] = 1;    input.segmentlist[3] = 2;
    input.segmentlist[4] = 2;    input.segmentlist[5] = 3;
    input.segmentlist[6] = 3;    input.segmentlist[7] = 4;
    input.segmentlist[8] = 4;    input.segmentlist[9] = 5;
    input.segmentlist[10] = 5;   input.segmentlist[11] = 0;

    /* Initialize output buffer */
    memset( &output, 0, sizeof( output ) );

    sprintf( options, "Dpza%f", maxarea );
    triangulate( options, &input, &output, NULL );

    mesh->verts = output.pointlist;
    mesh->num_verts = output.numberofpoints;
    mesh->tris = output.trianglelist;
    mesh->num_tris = output.numberoftriangles;

    free( input.pointlist );
    free( input.segmentlist );
    free( output.pointmarkerlist );
    free( output.segmentmarkerlist );
    free( output.segmentlist );

}
