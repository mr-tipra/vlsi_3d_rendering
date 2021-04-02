/*===============================================================*/
/*                                                               */
/*                       check_result.cpp                        */
/*                                                               */
/*      Software evaluation of training and test error rate      */
/*                                                               */
/*===============================================================*/

#include <cstdio>
#include "typedefs.h"
#include <fstream>
#include <iostream>
#include <string>


#ifndef SW
bool check_results(bit32* output,std::string& golden_file)
#else
bool check_results(bit8 output[MAX_X][MAX_Y], std::string& golden_file)
#endif
{
  #ifndef SW
    bit8 frame_buffer_print[MAX_X][MAX_Y];
  
    // read result from the 32-bit output buffer
    for (int i = 0, j = 0, n = 0; n < NUM_FB; n ++ )
    {
      bit32 temp = output[n];
      frame_buffer_print[i][j++] = temp(7,0);
      frame_buffer_print[i][j++] = temp(15,8);
      frame_buffer_print[i][j++] = temp(23,16);
      frame_buffer_print[i][j++] = temp(31,24);
      if(j == MAX_Y)
      {
        i++;
        j = 0;
      }
    }
  #endif

  //open golden outputs file
  std::ifstream golden(golden_file);
  char golden_buffer[MAX_X][MAX_Y];
  std::string line;
  if(golden.is_open()){
    int i=0;
    while(std::getline(golden, line)){
      for(int j=0; j<line.size(); j++){
         golden_buffer[i][j] = line[j];
      }
      i++;
    }
    golden.close();
  }
  else{
    std::cout << "ERROR::REFERENCE GOLDEN FILE NOT OPENED\n";
    return false;

  }
  // print result
  std::ofstream ofile;
  ofile.open("outputs.txt");
  if (ofile.is_open())
  {
    ofile << "Image After Rendering: \n";
    for (int j = MAX_X - 1; j >= 0; j -- )
    {
      for (int i = 0; i < MAX_Y; i ++ )
      {
        int pix;
        #ifndef SW
          pix = frame_buffer_print[i][j].to_int();
        #else
          pix = output[i][j];
        #endif
        int golden_pix = golden_buffer[MAX_X-1-j][i] == '1'?1:0;
        int out_pix = pix?1:0;
        if(golden_pix != out_pix) return false;

        if (pix){
          ofile << "1";
          std::cout << "1";
        }
        else{
          ofile << "0";
          std::cout << "0";
        }
      }
      ofile << std::endl;
      std::cout << "\n";
    }
  }
  else
  {
    std::cout << "Failed to create output file!" << std::endl;
  }
  return true;
}
