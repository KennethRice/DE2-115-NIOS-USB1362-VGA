/* AUTOR: Holguer A Becerrra
 * Semillero ADT
 * https://sites.google.com/site/semilleroadt/
 * */


#include "draw_gimps.h"
#include "gimp_bmp.h"
#include "../Pantalla/alt_video_display.h"



int AsVidCopyImageToBuffer( char* dest, char* src, 
                            int dest_width, 
                            int src_width, int src_height )
{
  int y;
  
  //Copy one line at a time from top to bottom
  for ( y = 0; y < src_height; y++ )
  {
    memcpy( dest, src, ( src_width * 4 ));
    src += ( src_width * 4 );
    dest += ( dest_width * 4 );
  }
  
  return( 0 );
}


void DispIMAGE( void * display_in, int x, int y,void * _image_in)
{
    
  alt_video_display * display = (alt_video_display *)display_in;
  struct gimp_image_struct * image_in=(struct gimp_image_struct *)_image_in;
  
  bitmap_struct* image;
  char* image_dest;
  struct gimp_image_struct* CIII_image;
  
  //CIII_image = &gimp_image_CIII_logo;
  
   CIII_image = image_in;
  
   
  
  image = malloc(sizeof(bitmap_struct));

  if( image != NULL )
  {
    //บบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ
      
    // Load the CIII logo
    load_gimp_bmp( CIII_image, image, 32);
      
    image_dest = (char*)(( display->buffer_ptrs[display->buffer_being_written]->buffer ) + (((( y ) ) * display->width ) * 4 ) +
                         ((( x)  ) * 4 ));
    
       AsVidCopyImageToBuffer(image_dest,
                            image->data, 
                            display->width, 
                            image->biWidth, 
                            image->biHeight );
                      
   
       
      
      


    free( image->data );  
    free( image );
    
    
   
  }
} 

