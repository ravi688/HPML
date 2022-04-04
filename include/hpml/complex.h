

#pragma once


typedef union complex_t
{
	struct 
	{
		float x, y;			// catesian coordiantes
	};

	struct
	{
		float r, arg; 		// polar coordinates
	};
} complex_t;


