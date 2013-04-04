fn main()
{
    for int::range(2,10) |i|
    {
        for int::range(1,10) |j|
        {
            io::println(fmt!("%d * %d = %d",i,j,i*j));
        }
    }
}