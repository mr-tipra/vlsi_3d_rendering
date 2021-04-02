/*===============================================================*/
/*                                                               */
/*                        check_result.h                         */
/*                                                               */
/*      Compare result and expected label to get error rate      */
/*                                                               */
/*===============================================================*/

#ifndef SW
bool check_results(bit32* output, std::string& golden_file);
#else
bool check_results(bit8 output[MAX_X][MAX_Y],std::string& golden_file);
#endif
