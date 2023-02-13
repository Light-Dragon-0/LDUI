#include "Bitmap.hpp"

class Image
{
public:
    Bitmap* bitmap;
    static Image* fromBitmap();
    static Image* fromFile();
};