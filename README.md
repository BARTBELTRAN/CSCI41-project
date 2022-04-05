# CSCI41-project

1.) Affected files include CountryManip.cpp, CountryManip.h, SeasonAllergy.h, and SeasonalAllergies.cpp. We had implemented a 
merge sorting algorithm in CountryManip.cpp and SeasonalAllergies.cpp. A binary search function can be found in CountryManip.cpp
In order to find the complexity of the sorting function, we have created a variable before and after. Before is intialized
at the beginning of the function and after is initialized after the merging is finished. IN order to get the complexity, we
Subtracted before from after to get the total time elapsed during the sort. This can be found during the call to the sorting
function in our Menu.h header file. It can be found in Case 4 of the menuCountry function and Case 4 of the pollenMenu function

2.) In order to address some feedback, we had changed the class name of DynamicArray to CountryArray in the CountryManip.h 
header file. This change makes it more clear as to the contents of the dynamicArray. In the future, we plan to condense the
merge sort functions so instead of having 4 functions, we hope to have 3 or even 2 functions

CountryManip.cpp lines 271 - 414
SeasonalAllergies.cpp lines 151 - 273
