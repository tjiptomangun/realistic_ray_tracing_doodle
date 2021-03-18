#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//https://stackoverflow.com/questions/849211/shortest-distance-between-a-point-and-a-line-segment/
/*
./line_point_intersection \(272.47595264191636,56.24999999999983\) \(240.0,0.0\) \(304.5,111.71727708819257\)
./line_point_intersection \(272.47595264191636,56.24999999999983\) \(253.0,56.249999999999766\) \(283.0,56.249999999999766\)
*/

typedef struct{
	double x, y;
} point;

double pDistance(double x, double y, double x1, double y1, double x2, double y2) {

  double A = x - x1;
  double B = y - y1;
  double C = x2 - x1;
  double D = y2 - y1;

  double dot = A * C + B * D;
  double len_sq = C * C + D * D;
  double param = -1;
  if (len_sq != 0) //in case of 0 length line
      param = dot / len_sq;

  double xx, yy;

  if (param < 0) {
    xx = x1;
    yy = y1;
  }
  else if (param > 1) {
    xx = x2;
    yy = y2;
  }
  else {
    xx = x1 + param * C;
    yy = y1 + param * D;
  }

  double dx = x - xx;
  double dy = y - yy;
  return sqrt(dx * dx + dy * dy);
}

double pDist3(point *tp, point *lstart, point *lend) {
	return pDistance(tp->x, tp->y, lstart->x, lstart->y, lend->x, lend->y);
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


int main(int argc, char **argv) {
	double c;

	if (argc < 4) {
		printf("Usage: %s <four points specified as (x,y) \
separated by a space>", argv[0]);
	}
	else {
		point p1 = extractPoint(argv[1]);
		point p2 = extractPoint(argv[2]);
		point p3 = extractPoint(argv[3]);

		c = pDist3(&p1, &p2, &p3);	

		fprintf(stdout, "distant %lf\n", c);
	}
}
