在 WinZlog 基础上的工程 
https://github.com/lopsd07/WinZlog.git

使用VS2010建立的完整工程。

当前目录的 Release 文件夹下有VS2010编译生成的.lib和.dll及zlog头文件


Release\bin

工程编译生成的 dll,

测试demo:test.exe，

zlog配置文件:zlog.conf 


Release\demo
test.c: test工程使用的测试代码,编译后生成 test.exe


Release\head
zlog.h：zlog头文件

Release\lib
工程编译生成的 lib


编译工程依赖两个库：

Requires the glob function from the Unixem project: 
http://synesis.com.au/software/unixem.html 

Requires the pthreads-win32 library: 
http://www.sourceware.org/pthreads-win32/
