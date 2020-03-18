#include <stdio.h>
#include <stdlib.h>

//------ POINT ----------------------------------------------------------------
typedef struct point point;
struct point { double x, y; };
//------ SQUARE -----------------------------------------------------------------
typedef struct square square;
struct square { point ul; double side; }; //Changed side from size_t to double, didn't make sense to have it as size_t

square* square_init(double ulx, double uly, double side) {
	square* sq = (square*)malloc(sizeof(square));
	point ul = {ulx, uly};
	sq->ul = ul;
	sq->side = side;
	return sq;
}

void square_delete(square* sq) {
	free(sq);
}

void square_move(square* sq, double x, double y) {
	point moved = {x, y};
	sq->ul = moved;
}

void square_expandby(square* sq, double expandby) {
	sq->side += expandby;
}

double square_area(square* sq) {
	return sq->side * sq->side;
}

double square_perimeter(square* r) {
	return r->side * 4;
}

// print location, side, area and perimeter
void square_print(const char* msg, square* sq) {
	printf("%s\n", msg);
	printf("location(ul): %.1f, %.1f\tside: %.1f\tarea: %.1f\tperimeter: %.1f\n\n", sq->ul.x, sq->ul.y, sq->side, square_area(sq), square_perimeter(sq));
}

void test_square(double ulx, double uly, double side) {
	square* sq = square_init(ulx, uly, side);
	square_print("sq is: ", sq);
	square_move(sq, 2, 2);
	square_print("sq is now: ", sq);
	square_expandby(sq, 10);
	square_print("sq has expanded to: ", sq);
	square_delete(sq);
	printf("\n\n");
}

void tests_square() {
	test_square(0, 0, 10);
	test_square(1, 1, 5);
	// add other tests if you wish // TODO (optional)
}

int main(int argc, const char* argv[]) {
	tests_square();
	return 0;
}