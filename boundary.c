void boundaryFill4 (int x, int y, int llColor, int borderColor)

{
int interiorColor;
/* Set current color to llColor, then perform following oprations. */
getPixel (x, y, interiorColor);
if ((interiorColor != borderColor) && (interiorColor != llColor)) f
setPixel (x, y); // Set color of pixel to llColor.
boundaryFill4 (x + 1, y , llColor, borderColor);
boundaryFill4 (x - 1, y , llColor, borderColor);
boundaryFill4 (x , y + 1, llColor, borderColor);
boundaryFill4 (x , y - 1, llColor, borderColor);
}
}