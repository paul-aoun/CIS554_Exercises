// Fig. 6.25: maximum.h
// Function template maximum header
template < typename T > // or template< class T>
T maximum(T value1, T value2, T value3, T value4)
{
	T maximumValue = value1; // assume value1 is maximum

	// determine whether value2 is greater than maximumValue
	if (value2 > maximumValue)
		maximumValue = value2;

	// determine whether value3 is greater than maximumValue
	if (value3 > maximumValue)
		maximumValue = value3;

	// determine whether value2 is greater than maximumValue
	if (value4 > maximumValue)
		maximumValue = value4;

	return maximumValue;

} // end function template maximum

