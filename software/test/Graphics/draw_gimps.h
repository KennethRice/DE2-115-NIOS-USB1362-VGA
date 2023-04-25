#ifndef DRAW_GIMPS_H_
#define DRAW_GIMPS_H_



int AsVidCopyImageToBuffer( char* dest, char* src, 
                            int dest_width, 
                            int src_width, int src_height );
                            
void DispIMAGE( void * display_in, int x, int y,void * _image_in);                            


#endif /*DRAW_GIMPS_H_*/
