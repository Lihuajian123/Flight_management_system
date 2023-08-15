#ifndef _BLACK_H
#define _BLACK_H

// 设置黑名单的函数
void Set_blacklist();
// 取消黑名单的函数
void re_blacklist();
// 检查用户名是否在黑名单中
int is_in_blacklist(const char *username);
#endif