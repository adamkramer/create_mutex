/*  This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

  	This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
 
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

	  Created by Adam Kramer [2015] - Email: adamkramer at hotmail dot com */

#include "stdafx.h"
#include "wchar.h"
#include "windows.h"


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Create Mutex - Adam Kramer [2015]\n\n");
	printf("This program will create one or more mutex as specified by the passed arguments and keep them active as long as the program keeps running.\n\n");

	if (argc < 2) 
	{
		printf("Usage: create_mutex [mutex 1] [mutex 2] [mutex 3] ...\n");
		return 1;
	}

	for (int i = 1; i < argc; i++)
		if (CreateMutex(NULL, TRUE, argv[i]))
			wprintf(L"Mutex: %s successfully created\n", argv[i]);
		else
			wprintf(L"Mutex: %s could not be created\n", argv[i]);

	printf("Info: Now fully launched, use Ctrl+C to exit");

	for (;;)
		Sleep(10000);

	return 0;
}

