#pragma once
#include <iostream>
#include "ConsoleLib.h"
#include "List-old.h"
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;

#define H 25
#define W 50

enum btype { Space = ' ', Border = 219, Snake_HeadU = '^', Snake_HeadD = 'V', Snake_HeadL = '<', Snake_HeadR = '>', Snake_BodyH = '-', Snake_BodyV = '|' , Apfel = '@' };
enum side { Up = 'w', Down = 's', Left = 'a', Right = 'd' };
enum fieldsigns { snakee = 1, appple = 2 };