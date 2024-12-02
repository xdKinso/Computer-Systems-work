extern "C" void kmain()
{
    const short colour = 0x0f00;

    const char* hello = "we're now in C++";

    short* vga = (short*)0xb8000;

    for (int i = 0; i < 16; ++i)
    {
        vga[i+80] = colour | hello[i];
    }
}