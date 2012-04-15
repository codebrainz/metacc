/*
 * The World's first Meta C file.
 */
#import <stdlib.h>

/* This is multi-line comment */
// This is a single-line comment

 class Foo {
 /* private is the default
 @private:
 */
 	int privateInteger;
 @public:
 	int GetPrivateInteger();
 	void SetPrivateInteger(int i);
 };

int main(int argc, char *argv)
{
	printf("metac: Hello %s\n", "World!");
	return 0;
}
