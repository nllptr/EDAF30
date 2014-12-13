#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

template <class T>
T *bin_sok(T sokt, T *forsta, T *sista)
{
    if(forsta > sista)
        return 0;
    T *mitten = forsta + (sista - forsta) / 2;
    if(sokt < *mitten)
        return bin_sok(sokt, forsta, mitten - 1);
    else if(sokt > *mitten)
        return bin_sok(sokt, mitten + 1, sista);
    else
        return mitten;
}

#endif // BINARYSEARCH_H
