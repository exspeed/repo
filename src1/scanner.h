#ifndef __SCANNER_H__
#define __SCANNER_H__
enum token_type { end_token, num_token, op_token };
void get_token();
enum token_type curr_token;
void init_scanner();
#endif
