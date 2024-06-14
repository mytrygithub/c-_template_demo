#include<string>
#include<iostream>
#include <stdlib.h>
#include<iostream>

using std::cout;
using std::endl;
using std::system;
using std::string;

void exec_my_cmd(const string cmd) {  
    FILE *fp;  
    int status;  
  
    // 使用popen执行bash命令  
    fp = popen(cmd.c_str(), "r");  
    if (fp == NULL) {  
        perror("popen failed:");  
        return;  
    }
  
    // 读取命令输出（可选）  
    char buffer[1024];  
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {  
        cout << buffer;
    }
    //cout << endl;
  
    // 使用pclose关闭进程并获取返回值  
    status = pclose(fp);  
    if (WIFEXITED(status)) {  
        //int exit_status = WEXITSTATUS(status);  
        //cout << "Command exited with status " << exit_status << endl;  
    } else if (WIFSIGNALED(status)) {  
        int signal_number = WTERMSIG(status);  
        cout << "Command was killed by signal " << signal_number << endl;  
    }
}

void printf_type_info(const string variable, const string typeinfo) {
	cout << variable << ":\t";
	string cmd{"c++filt --type "};
	cmd.append(typeinfo);
	exec_my_cmd(cmd);
}