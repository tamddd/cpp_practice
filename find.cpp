templete<class In, class T>
        In find(In first, In last, const T& val)
{
    while (first != last && *first != val) ++ first;
    return first;
}