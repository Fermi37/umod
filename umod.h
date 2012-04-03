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
#ifndef __UMOD_H__
#define __UMOD_H__

struct umod_mesh_s
{
    double *verts;
    int *tris;
    size_t num_verts;
    size_t num_tris;
};

void umod_mesh_free( struct umod_mesh_s *mesh );
void umod_mesh_output( const char *name, struct umod_mesh_s *mesh );
void umod_mesh_lshaped( double dx, double dy, double maxarea, struct umod_mesh_s *mesh );


#endif /* __UMOD_H__ */
