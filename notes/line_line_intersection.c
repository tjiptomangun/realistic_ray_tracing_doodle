#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//rosettacode.org/wiki/Find_the_intersection_of_two_lines#C
//https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection
/*
 y1 = ax + c
 y2 = bx + d
 bertemu di ?
 y1 = y2 (karena linear)
 ax + c = bx + d
 ax - bax = d - c
 sehingga
 x = (d - c) / (a - b)
 y = ax + c
   = (a(d - c)/ (a - b)) + c
*/


typedef struct{
	double x, y;
} point;

double lineSlope(point a, point b){
	if (a.x - b.x == 0.0){
		return NAN;
	}
	else {
		return (a.y - b.y)/(a.x - b.x);
	}
}

point extractPoint(char *str) {
	int i, j, start, end, length;
	char *holder = NULL;
	point c;

	for(i = 0; str[i]!=0; i++){
		if(str[i] == '('){
			start = i;
		}
		if (str[i] == ',' || str[i] == ')'){
			end = i;

			length = end - start;
			holder = (char *) malloc(length * sizeof(char));
			for (j = 0; j < length - 1; j++){
				holder[j] = str[start + j + 1];
			}
			holder[j] = 0x00;

			if(str[i] == ','){
				start = i;
				c.x = atof(holder);
			}
			else {
				c.y = atof(holder);
			}
			if (holder) {
				free(holder);
				holder = NULL;
			}
		}
	}
	return c;
}

point intersectionPoint(point a1, point a2, point b1, point b2){
	point c;

	double slopeA = lineSlope(a1, a2);
	double slopeB = lineSlope(b1, b2);

	if (slopeA == slopeB) {
		c.x = NAN;
		c.y = NAN;
	}
	else if(isnan(slopeA) && !isnan(slopeB)) {
		c.x = a1.x;
		c.y = (a1.x	- b1.x)*slopeB + b1.y;
	}
	else if(isnan(slopeB) && !isnan(slopeA)) {
		c.x = b1.x;
		c.y = (b1.x	- a1.x)*slopeA + a1.y;
	}
	else {
		c.x = (slopeA*a1.x - slopeB*b1.x + b1.y - a1.y)/(slopeA - slopeB);
		c.y = slopeB*(c.x - b1.x) + b1.y;
	}

	return c;
}

int main(int argc, char **argv) {
	point c;

	if (argc < 5) {
		printf("Usage: %s <four points specified as (x,y) \
separated by a space>", argv[0]);
	}
	else {
		point p1 = extractPoint(argv[1]);
		point p2 = extractPoint(argv[2]);
		point p3 = extractPoint(argv[3]);
		point p4 = extractPoint(argv[4]);

		c = intersectionPoint(p1, p2, p3, p4);	

		if (isnan(c.x)) {
			fprintf(stdout, "Lines are not intersect\n");
		}
		else {
			fprintf(stdout, "intersection (%lf, %lf)", c.x, c.y);
		}
	}
}
