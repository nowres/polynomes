#include <stdio.h>
#include <stdlib.h>
#include <libpolynomes.h>

int main()
{
    double poly_vals [] = {2,5,1}; /** P(x) = 2x^2 + 5x + 1 **/
    double val;
    polynome_t *poly;
    poly = create_polynome ();
    set_polynome (poly , poly_vals , 2 );
    polynome_value (poly , 1 , &val); /** calculating P(1) / val = P(1) **/

    printf("P(1) = %lf",val);
    return 0;
}
