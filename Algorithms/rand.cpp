 random_device rd;     //Get a random seed from the OS entropy device, or whatever
 mt19937_64 eng(rd()); //Use the 64-bit Mersenne Twister 19937 generator and seed it with entropy.
 //Define the distribution, by default it goes from 0 to MAX(unsigned long long)
 uniform_int_distribution<unsigned long long> distr;
 unsigned long long getRand() { return distr(eng); }

