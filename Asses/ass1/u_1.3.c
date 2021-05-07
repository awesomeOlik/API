#include <stdio.h>
#include <float.h>

int main(int argc, char* argv[])
{
	float sef = 1.0;
	double sed = 1.0;

	while (1 + (sef / 2) > 1) {
		sef = sef / 2;
	}
	printf("Strojove epsilon pre float %e\n", sef);

	while (1 + (sed / 2) > 1) {
		sed = sed / 2;
	}
	printf("Strojove epsilon pre double %e\n", sed);

	return 0;
}

