#include <discid/discid.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    DiscId *disc = discid_new();
    if ( discid_read_sparse(disc, "/dev/cdrom", 0) == 0 ) {
        fprintf(stderr, "Error: %s\n", discid_get_error_msg(disc));
        return 1;
    }
    printf("DiscID        : %s\n", discid_get_id(disc));
    printf("Submit via    : %s\n", discid_get_submission_url(disc));
    discid_free(disc);

    return 0;
}