# CST276SRS02  

Date Validation Strategy/Template Method  

Name: Tanel Helmik

---
Issues:  No Issues detected at this time


Notes:  
DATEI18N uses the GOF Strategy pattern
Currently dates are only delimited by "/"

    - Add the new YDM format to both DateI18NEnum and DateI18N projects, noting the places where you had to modify your implementation to handle the new format.  

	Date18N:  I had to add a class and then use the class.
	DateI18NEnum: I had to put another case into the switch statement which required another enum class type and then I had to make sure I added the conditional to handle the new format input string

    - In your report, note the differences between what it took to modify the code for both projects, include both pros and cons for each project design.  

	I liked that for the DateI18N I only had to add a class that made it easier.  The con is that there is a lot of duplicated code.  
	I didn't like that I had to add code in multiple places in the enum version.  The pro of the enum is that it's less space consuming. (takes up less memory)
###

