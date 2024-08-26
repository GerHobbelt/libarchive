// SPDX-License-Identifier: 0BSD
#include "test.h"

static const char data[] = "!<arch>\narchivemount.1/ 0           0     0     644     0         `\n";


DEFINE_TEST(test_ar_mode)
{
	struct archive * ar = archive_read_new();
	assertEqualInt(archive_read_support_format_all(ar), ARCHIVE_OK);
	assertEqualInt(archive_read_open_memory(ar, data, sizeof(data) - 1), ARCHIVE_OK);

	struct archive_entry * entry;
	assertEqualIntA(ar, archive_read_next_header(ar, &entry), ARCHIVE_OK);
	assertEqualIntA(ar, archive_entry_mode(entry), S_IFREG | 0644);

	archive_read_free(ar);
}
