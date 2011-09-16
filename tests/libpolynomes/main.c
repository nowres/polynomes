#include <stdio.h>
#include <stdlib.h>
#include <libpolynomes.h>

int main()
{
    double poly_vals [] = {2,5,1};
    double val;
    polynome_t *poly;
    poly = create_polynome ();
    set_polynome (poly , poly_vals , 2 );
    polynome_value (poly , 1 , &val);

    printf("P(2) = %lf",val);
    return 0;
}
