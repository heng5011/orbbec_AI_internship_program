/*
The MIT License

Copyright (c) 2007-2010 Aidin Abedi http://code.google.com/p/shinyprofiler/

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "Shiny.h"


#ifdef _WIN32
#include <windows.h> // Sleep
#else // assume POSIX
#include <unistd.h> // usleep
#endif


/*---------------------------------------------------------------------------*/

void millisleep(unsigned int milliseconds) {
#ifdef _WIN32
	Sleep(milliseconds);
#else
	usleep(milliseconds * 1000);
#endif
}


/*---------------------------------------------------------------------------
*/

void LazyHelloWorld(void) {

	// Func测一整个函数，block测函数中的某一段，
	PROFILE_FUNC(); // profile until end of block (only supported in c++)	ShinyPrereqs.h 97行

	millisleep(100);
}


/*---------------------------------------------------------------------------*/

void HelloWorld(void) {

	/* PROFILE_BEGIN()和PROFILE_END()配套使用，测一段程序; 
	PROFILE_BEGIN(), ()里面的内容为注释,方便查看输出结果;
	和PROFILE_BEGIN()配套使用
	
	*/
	PROFILE_BEGIN(Hello_World__This_is_Shiny); // profile until PROFILE_END()

	millisleep(100);

	PROFILE_END();
}


/*---------------------------------------------------------------------------*/

int main() {

	HelloWorld();

	LazyHelloWorld();

	PROFILE_UPDATE(); // update all profiles
	PROFILE_OUTPUT(NULL); // print to terminal

	// cout << timer().generateReport();
    // cout << "\n average time for start_threads: " << timer().getStatistics("start_threads") << "\n";
	
#ifdef _WIN32
	system("pause");
#endif
	return 0;
}
