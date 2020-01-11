#include <iostream>
#include <fstream>
#include <type_traits>


using namespace std;


/***
 * Thought Process towards Solution
 * 
 * As the problem statement states that only legal move for (x,y) is either (x,y+x) or (x+y,y)
 * and this problem has a pattern in reaching the destination so conversely tracing the path would be quick solution
 * trying to reach the source from destination i.e.,
 * a leagal move for (tx,ty) to reach (sx,sy) is either (tx-ty,ty) or (tx,ty-tx)
 * ***/
 
 
 /***
  * Method 1:
  * As I am taking a reverse approach and the problem is a series of subtractions at each step
  * A common method of matching a Greatest Common Divisor of starting and target will solve the problem
  * In fining the GCD of 2 numbers we can use Euclidean algorithm for fining the GCD
  * ***/

 /***
  * Assumptions 
  * 
  * starting points (sx,sy) and target points (tx,ty) all are positive integers
  * Since the Range of the Numbers is not mentioned created templates to accomodate different number data types(int and long)
  * ***/

/***
 * ***************************************** UTILs Methods**********************************
 * ***/


// Depending on type of inputs given in the file convertStringToType method will return convertion from string to given data type
template <typename T>
T convertStringToType(string value)
{   
    try{
        if(std::is_same<T,int>::value)
        {
            return std::stoi(value);
        }
        else if(std::is_same<T,long>::value)
        {
            return std::stol(value);
        }
        
    }
    catch(char *e)
    {
        cout<<"Catch Exception: "<<e<<endl;
    }
}


// Reading starting and target points from a file and assigning them to variables in the method
template <typename T>
 void readInputs(string fileName,T *sx,T *sy,T *tx,T *ty)
 {
     ifstream inputFile(fileName);
     string tempValue="";

    inputFile>>tempValue;
    *sx = convertStringToType<T>(tempValue);

    inputFile>>tempValue;
    *sy = convertStringToType<T>(tempValue);

    inputFile>>tempValue;
    *tx = convertStringToType<T>(tempValue);

    inputFile>>tempValue;
    *ty = convertStringToType<T>(tempValue);
 }



/***
 * ******************************************* END OF UTILs Methods ********************************************
 * ***/



/***
 * *************************** Starting Logic Methods ***********************************************************
 * ***/

/***
 * gcd method uses Euclidean Algorithm that for finding series of subractions can be replaced by divider of larger number with smaller number
 * ***/
template <typename T>
 T gcd(T a,T b)
 {
     if(a==0)
     {
         return b;
     }
     else
     {
         return gcd(b%a,a);
     }
     
 }

/***
 * is_PathExistis Method checks
 * if starting point and target points gcd is equal
 * returns true 
 * else returns false
 * ***/
template <typename T>
 bool is_PathExists(T sx,T sy,T tx,T ty)
 {
     if(gcd(sx,sy)==gcd(tx,ty))
     {
         return true;
     }
     else
     {
         return false;
     }
     
 }
/***
 * *************************** END Logic Methods ***********************************************************
 * ***/



int main()
{
    string inputFile = "inputs.txt";
    long sx=0,sy=0,tx=0,ty=0;

    readInputs<long>(inputFile,&sx,&sy,&tx,&ty);

    std::cout<<sx<<"    "<<sy<<"    "<<tx<<"    "<<ty<<endl;

    if(is_PathExists(sx,sy,tx,ty))
    {
        cout<<"Path Exists"<<endl;
    }
    else
    {
        cout<<"Path Does Not Exists"<<endl;
    }
    


    return 0;
}
