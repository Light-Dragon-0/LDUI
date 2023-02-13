#include "vector2.hpp"
/*
nothing (default)
#define VECTOR2_FLOAT
#define VECTOR2_DOUBLE 
#define VECTOR2_LONGDOUBLE
#define VECTOR2_CUSTOM requires def [VECTOR2_CUSTOM_FLOOR,VECTOR2_CUSTOM_ROUND,VECTOR2_CUSTOM_CEIL,VECTOR2_CUSTOM_SQRT]
*/
template<typename numericT>
vector2<numericT>::vector2()
{
    this->x = numericT();
    this->y = numericT();
}
template<typename numericT>
vector2<numericT>::vector2(numericT value)
{
    this->x = value;
    this->y = value;
}
template<typename numericT>
vector2<numericT>::vector2(numericT x,numericT y)
{
    this->x = x;
    this->y = y;
}
template<typename numericT>
vector2<numericT>::vector2(vector2<numericT>& copy)
{
    this->x = copy.x;
    this->y = copy.y;
}
template<typename numericT>
vector2<numericT> vector2<numericT>::add(vector2<numericT>& b)
{
    return vector2(this->x + b.x, this->y + b.y);
}
template<typename numericT>
void vector2<numericT>::add_eq(vector2<numericT>& b)
{
    this->x += b.x;
    this->y += b.y;
}
template<typename numericT>
vector2<numericT> vector2<numericT>::add(vector2<numericT>& a,vector2<numericT>& b)
{
    return vector2(a.x + b.x, a.y + b.y);
}
template<typename numericT>
vector2<numericT> vector2<numericT>::operator+(vector2<numericT>& b)
{
    return vector2(this->x + b.x, this->y + b.y);
}
template<typename numericT>
void vector2<numericT>::operator+=(vector2<numericT>& b)
{
    this->x += b.x;
    this->y += b.y;
}
template<typename numericT>
vector2<numericT> vector2<numericT>::sub(vector2<numericT>& b)
{
    return vector2<numericT>(this->x - b.x,this->y - b.y);
}
template<typename numericT>
void vector2<numericT>::sub_eq(vector2<numericT>& b)
{
    this->x -= b.x;
    this->y -= b.y;
}
template<typename numericT>
vector2<numericT> vector2<numericT>::sub(vector2<numericT>& a,vector2<numericT>& b)
{
    return vector2<numericT>(a.x - b.x,a.y - b.y);
}
template<typename numericT>
vector2<numericT> vector2<numericT>::operator-(vector2<numericT>& b)
{
    return vector2(this->x - b.x,this->y - b.y);
}
template<typename numericT>
void vector2<numericT>::operator-=(vector2<numericT>& b)
{
    this->x -= b.x;
    this->y -= b.y;
}
template<typename numericT>
vector2<numericT> vector2<numericT>::mul(vector2<numericT>& b)
{
    return vector2(this->x * b.x,this->y * b.y);
}
template<typename numericT>
void vector2<numericT>::mul_eq(vector2<numericT>& b)
{
    this->x *= b.x;
    this->y *= b.y;
}
template<typename numericT>
vector2<numericT> vector2<numericT>::mul(vector2<numericT>& a,vector2<numericT>& b)
{
    return vector2(a.x * b.x,a.y * b.y);
}
template<typename numericT>
vector2<numericT> vector2<numericT>::operator*(vector2<numericT>& b)
{
    return vector2(this->x * b.x,this->y * b.y);
}
template<typename numericT>
void vector2<numericT>::operator*=(vector2<numericT>& b)
{
    this->x *= b.x;
    this->y *= b.y;
}
template<typename numericT>
vector2<numericT> vector2<numericT>::div(vector2<numericT>& b)
{
    return vector2(this->x / b.x,this->y / b.y);
}
template<typename numericT>
void vector2<numericT>::div_eq(vector2<numericT>& b)
{
    this->x /= b.x;
    this->y /= b.y;
}
template<typename numericT>
vector2<numericT> vector2<numericT>::div(vector2<numericT>& a,vector2<numericT>& b)
{
    return vector2(a.x / b.x, a.y / b.y);
}
template<typename numericT>
vector2<numericT> vector2<numericT>::operator/(vector2<numericT>& b)
{
    return vector2(this->x / b.x, this->y / b.y);
}
template<typename numericT>
void vector2<numericT>::operator/=(vector2<numericT>& b)
{
    this->x /= b.x;
    this->y /= b.y;
}
template<typename numericT>
vector2<numericT> vector2<numericT>::floor_c()
{
    #ifdef VECTOR2_FLOAT
        vector2<numericT> vec;
        vec.x = floorf(this->x);
        vec.y = floorf(this->y);
        return vec;
    #else
        #ifdef VECTOR2_DOUBLE
            vector2<numericT> vec;
            vec.x = floor(this->x);
            vec.y = floor(this->y);
            return vec;
        #else
            #ifdef VECTOR2_LONGDOUBLE
                vector2<numericT> vec;
                vec.x = floorl(this->x);
                vec.y = floorl(this->y);
                return vec;
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_FLOOR
                        vector2<numericT> vec;
                        vec.x = VECTOR2_CUSTOM_FLOOR(this->x);
                        vec.y = VECTOR2_CUSTOM_FLOOR(this->y);
                        return vec;
                    #else
                        #error missing definition for VECTOR2_CUSTOM_FLOOR, must be defined when VECTOR2_CUSTOM is defined
                    #endif
                #else
                    #warning no preprocessor defined for vector2, some functions are not going to work! , vector2 preprocessors [VECTOR2_FLOAT,VECTOR2_DOUBLE,VECTOR2_LONGDOUBLE,VECTOR2_CUSTOM,(or nothing)]
                #endif
            #endif
        #endif
    #endif
}
template<typename numericT>
void vector2<numericT>::floor_c_eq()
{
    #ifdef VECTOR2_FLOAT
        this->x = floorf(this->x);
        this->y = floorf(this->y);
    #else
        #ifdef VECTOR2_DOUBLE
            this->x = floor(this->x);
            this->y = floor(this->y);
        #else
            #ifdef VECTOR2_LONGDOUBLE
                this->x = floorl(this->x);
                this->y = floorl(this->y);
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_FLOOR
                        this->x = VECTOR2_CUSTOM_FLOOR(this->x);
                        this->y = VECTOR2_CUSTOM_FLOOR(this->y);
                    #else
                        #error missing definition for VECTOR2_CUSTOM_FLOOR, must be defined when VECTOR2_CUSTOM is defined
                    #endif
                #else
                    #warning no preprocessor defined for vector2, some functions are not going to work! , vector2 preprocessors [VECTOR2_FLOAT,VECTOR2_DOUBLE,VECTOR2_LONGDOUBLE,VECTOR2_CUSTOM,(or nothing)]
                #endif
            #endif
        #endif
    #endif
}
template<typename numericT>
vector2<numericT> vector2<numericT>::floor_c(vector2<numericT>& a)
{
    #ifdef VECTOR2_FLOAT
        vector2<numericT> vec;
        vec.x = floorf(a.x);
        vec.y = floorf(a.y);
        return vec;
    #else
        #ifdef VECTOR2_DOUBLE
            vector2<numericT> vec;
            vec.x = floor(a.x);
            vec.y = floor(a.y);
            return vec;
        #else
            #ifdef VECTOR2_LONGDOUBLE
                vector2<numericT> vec;
                vec.x = floorl(a.x);
                vec.y = floorl(a.y);
                return vec;
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_FLOOR
                        vector2<numericT> vec;
                        vec.x = VECTOR2_CUSTOM_FLOOR(a.x);
                        vec.y = VECTOR2_CUSTOM_FLOOR(a.y);
                        return vec;
                    #else
                        #error missing definition for VECTOR2_CUSTOM_FLOOR, must be defined when VECTOR2_CUSTOM is defined
                    #endif
                #else
                    #warning no preprocessor defined for vector2, some functions are not going to work! , vector2 preprocessors [VECTOR2_FLOAT,VECTOR2_DOUBLE,VECTOR2_LONGDOUBLE,VECTOR2_CUSTOM,(or nothing)]
                #endif
            #endif
        #endif
    #endif
}
template<typename numericT>
vector2<numericT> vector2<numericT>::round_c()
{
    #ifdef VECTOR2_FLOAT
        vector2<numericT> vec;
        vec.x = roundf(this->x);
        vec.y = roundf(this->y);
        return vec;
    #else
        #ifdef VECTOR2_DOUBLE
            vector2<numericT> vec;
            vec.x = round(this->x);
            vec.y = round(this->y);
            return vec;
        #else
            #ifdef VECTOR2_LONGDOUBLE
                vector2<numericT> vec;
                vec.x = roundl(this->x);
                vec.y = roundl(this->y);
                return vec;
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_ROUND
                        vector2<numericT> vec;
                        vec.x = VECTOR2_CUSTOM_ROUND(this->x);
                        vec.y = VECTOR2_CUSTOM_ROUND(this->y);
                        return vec;
                    #else
                        #error missing definition for VECTOR2_CUSTOM_ROUND, must be defined when VECTOR2_CUSTOM is defined
                    #endif
                #else
                    #warning no preprocessor defined for vector2, some functions are not going to work! , vector2 preprocessors [VECTOR2_FLOAT,VECTOR2_DOUBLE,VECTOR2_LONGDOUBLE,VECTOR2_CUSTOM,(or nothing)]
                #endif
            #endif
        #endif
    #endif
}
template<typename numericT>
void vector2<numericT>::round_c_eq()
{
    #ifdef VECTOR2_FLOAT
        this->x = roundf(this->x);
        this->y = roundf(this->y);
    #else
        #ifdef VECTOR2_DOUBLE
            this->x = round(this->x);
            this->y = round(this->y);
        #else
            #ifdef VECTOR2_LONGDOUBLE
                this->x = roundl(this->x);
                this->y = roundl(this->y);
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_ROUND
                        this->x = VECTOR2_CUSTOM_ROUND(this->x);
                        this->y = VECTOR2_CUSTOM_ROUND(this->y);
                    #else
                        #error missing definition for VECTOR2_CUSTOM_ROUND, must be defined when VECTOR2_CUSTOM is defined
                    #endif
                #else
                    #warning no preprocessor defined for vector2, some functions are not going to work! , vector2 preprocessors [VECTOR2_FLOAT,VECTOR2_DOUBLE,VECTOR2_LONGDOUBLE,VECTOR2_CUSTOM,(or nothing)]
                #endif
            #endif
        #endif
    #endif
}
template<typename numericT>
vector2<numericT> vector2<numericT>::round_c(vector2<numericT>& a)
{
    
    #ifdef VECTOR2_FLOAT
        vector2<numericT> vec;
        vec.x = roundf(a.x);
        vec.y = roundf(a.y);
        return vec;
    #else
        #ifdef VECTOR2_DOUBLE
            vector2<numericT> vec;
            vec.x = round(a.x);
            vec.y = round(a.y);
            return vec;
        #else
            #ifdef VECTOR2_LONGDOUBLE
                vector2<numericT> vec;
                vec.x = roundl(a.x);
                vec.y = roundl(a.y);
                return vec;
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_ROUND
                        vector2<numericT> vec;
                        vec.x = VECTOR2_CUSTOM_ROUND(a.x);
                        vec.y = VECTOR2_CUSTOM_ROUND(a.y);
                        return vec;
                    #else
                        #error missing definition for VECTOR2_CUSTOM_ROUND, must be defined when VECTOR2_CUSTOM is defined
                    #endif
                #else
                    #warning no preprocessor defined for vector2, some functions are not going to work! , vector2 preprocessors [VECTOR2_FLOAT,VECTOR2_DOUBLE,VECTOR2_LONGDOUBLE,VECTOR2_CUSTOM,(or nothing)]
                #endif
            #endif
        #endif
    #endif
}
template<typename numericT>
vector2<numericT> vector2<numericT>::ceil_c()
{
    #ifdef VECTOR2_FLOAT
        vector2<numericT> vec;
        vec.x = ceilf(this->x);
        vec.y = ceilf(this->y);
        return vec;
    #else
        #ifdef VECTOR2_DOUBLE
            vector2<numericT> vec;
            vec.x = ceil(this->x);
            vec.y = ceil(this->y);
            return vec;
        #else
            #ifdef VECTOR2_LONGDOUBLE
                vector2<numericT> vec;
                vec.x = ceill(this->x);
                vec.y = ceill(this->y);
                return vec;
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_CEIL
                        vector2<numericT> vec;
                        vec.x = VECTOR2_CUSTOM_CEIL(this->x);
                        vec.y = VECTOR2_CUSTOM_CEIL(this->y);
                        return vec;
                    #else
                        #error missing definition for VECTOR2_CUSTOM_CEIL, must be defined when VECTOR2_CUSTOM is defined
                    #endif
                #else
                    #warning no preprocessor defined for vector2, some functions are not going to work! , vector2 preprocessors [VECTOR2_FLOAT,VECTOR2_DOUBLE,VECTOR2_LONGDOUBLE,VECTOR2_CUSTOM,(or nothing)]
                #endif
            #endif
        #endif
    #endif
}
template<typename numericT>
void vector2<numericT>::ceil_c_eq()
{
    #ifdef VECTOR2_FLOAT
        this->x = ceilf(this->x);
        this->y = ceilf(this->y);
    #else
        #ifdef VECTOR2_DOUBLE
            this->x = ceil(this->x);
            this->y = ceil(this->y);
        #else
            #ifdef VECTOR2_LONGDOUBLE
                this->x = ceill(this->x);
                this->y = ceill(this->y);
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_CEIL
                        this->x = VECTOR2_CUSTOM_CEIL(this->x);
                        this->y = VECTOR2_CUSTOM_CEIL(this->y);
                    #else
                        #error missing definition for VECTOR2_CUSTOM_CEIL, must be defined when VECTOR2_CUSTOM is defined
                    #endif
                #else
                    #warning no preprocessor defined for vector2, some functions are not going to work! , vector2 preprocessors [VECTOR2_FLOAT,VECTOR2_DOUBLE,VECTOR2_LONGDOUBLE,VECTOR2_CUSTOM,(or nothing)]
                #endif
            #endif
        #endif
    #endif
}
template<typename numericT>
vector2<numericT> vector2<numericT>::ceil_c(vector2<numericT>& a)
{
    #ifdef VECTOR2_FLOAT
        vector2<numericT> vec;
        vec.x = ceilf(a.x);
        vec.y = ceilf(a.y);
        return vec;
    #else
        #ifdef VECTOR2_DOUBLE
            vector2<numericT> vec;
            vec.x = ceil(a.x);
            vec.y = ceil(a.y);
            return vec;
        #else
            #ifdef VECTOR2_LONGDOUBLE
                vector2<numericT> vec;
                vec.x = ceill(a.x);
                vec.y = ceill(a.y);
                return vec;
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_CEIL
                        vector2<numericT> vec;
                        vec.x = VECTOR2_CUSTOM_CEIL(a.x);
                        vec.y = VECTOR2_CUSTOM_CEIL(a.y);
                        return vec;
                    #else
                        #error missing definition for VECTOR2_CUSTOM_CEIL, must be defined when VECTOR2_CUSTOM is defined
                    #endif
                #else
                    #warning no preprocessor defined for vector2, some functions are not going to work! , vector2 preprocessors [VECTOR2_FLOAT,VECTOR2_DOUBLE,VECTOR2_LONGDOUBLE,VECTOR2_CUSTOM,(or nothing)]
                #endif
            #endif
        #endif
    #endif
}
template<typename numericT>
vector2<numericT> vector2<numericT>::min_c(vector2<numericT>& b)
{
    return vector2(((this->x < b.x)?this->x:b.x),((this->y < b.y)?this->y:b.y));
} //returns the min of each component
template<typename numericT>
void vector2<numericT>::min_c_eq(vector2<numericT>& b)
{
    this->x = ((this->x < b.x)?this->x:b.x);
    this->y = ((this->y < b.y)?this->y:b.y);
}
template<typename numericT>
vector2<numericT> vector2<numericT>::min_c(vector2<numericT>& a,vector2<numericT>& b)
{
    return vector2(((a.x < b.x)?a.x:b.x),((a.y < b.y)?a.y:b.y));
}
template<typename numericT>
vector2<numericT> vector2<numericT>::min_l(vector2<numericT>& b)
{
    //there might be a way to optmize this ... unconfirmed solution
    if(this->det() < b.det())
        return this;
    else 
        return b;
} //returns the vector with min length
template<typename numericT>
void vector2<numericT>::min_l_eq(vector2<numericT>& b)
{
    if(b.det() < this->det())
        this = b;
}
template<typename numericT>
vector2<numericT> vector2<numericT>::min_l(vector2<numericT>& a,vector2<numericT>& b)
{
    if(a.det() < b.det())
        return a;
    else
        return b;
}
template<typename numericT>
vector2<numericT> vector2<numericT>::max_c(vector2<numericT>& b)
{
    return vector2(((this->x > b.x)?this->x:b.x),((this->y > b.y)?this->y:b.y));
} //returns the max of each component
template<typename numericT>
void vector2<numericT>::max_c_eq(vector2<numericT>& b)
{
    this->x = ((this->x > b.x)?this->x:b.x);
    this->y = ((this->y > b.y)?this->y:b.y);
}
template<typename numericT>
vector2<numericT> vector2<numericT>::max_c(vector2<numericT>& a,vector2<numericT>& b)
{
    return vector2(((a.x > b.x)?a.x:b.x),((a.y > b.y)?a.y:b.y));
}
template<typename numericT>
vector2<numericT> vector2<numericT>::max_l(vector2<numericT>& b)
{
    if(this->det() > b.det())
        return this;
    else
        return b;
} //returns the vector with max length
template<typename numericT>
void vector2<numericT>::max_l_eq(vector2<numericT>& b)
{
    if(this->det() < b.det())
        this = b;
}
template<typename numericT>
vector2<numericT> vector2<numericT>::max_l(vector2<numericT>& a,vector2<numericT>& b)
{
    if(a.det() < b.det())
        return b;
    else
        return a;
}
template<typename numericT>
numericT vector2<numericT>::length(vector2<numericT>& b)
{
    numericT dx = this->x - b.x;
    numericT dy = this->y - b.y;
    #ifdef VECTOR2_FLOAT
        return sqrtf(dx * dx + dy * dy);
    #else
        #ifdef VECTOR2_DOUBLE
            return sqrt(dx * dx + dy * dy);
        #else
            #ifdef VECTOR2_LONGDOUBLE
                return sqrtl(dx * dx + dy * dy);
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_SQRT
                        return VECTOR2_CUSTOM_SQRT(dx * dx + dy * dy);
                    #else
                        #error missing definition for VECTOR2_CUSTOM_SQRT, must be defined when VECTOR2_CUSTOM is defined
                    #endif
                #else
                    #warning no preprocessor defined for vector2, some functions are not going to work! , vector2 preprocessors [VECTOR2_FLOAT,VECTOR2_DOUBLE,VECTOR2_LONGDOUBLE,VECTOR2_CUSTOM,(or nothing)]
                #endif
            #endif
        #endif
    #endif
}
template<typename numericT>
void vector2<numericT>::length_c_eq(vector2<numericT>& b)
{
    numericT dx = this->x - b.x;
    numericT dy = this->y - b.y;
    numericT r;
    #ifdef VECTOR2_FLOAT
        r = sqrtf(dx * dx + dy * dy);
    #else
        #ifdef VECTOR2_DOUBLE
            r = sqrt(dx * dx + dy * dy);
        #else
            #ifdef VECTOR2_LONGDOUBLE
                r = sqrtl(dx * dx + dy * dy);
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_SQRT
                        r = VECTOR2_CUSTOM_SQRT(dx * dx + dy * dy);
                    #else
                        #error missing definition for VECTOR2_CUSTOM_SQRT, must be defined when VECTOR2_CUSTOM is defined
                    #endif
                #else
                    #warning no preprocessor defined for vector2, some functions are not going to work! , vector2 preprocessors [VECTOR2_FLOAT,VECTOR2_DOUBLE,VECTOR2_LONGDOUBLE,VECTOR2_CUSTOM,(or nothing)]
                #endif
            #endif
        #endif
    #endif
    this->x = r;
    this->y = r;
}
template<typename numericT>
numericT vector2<numericT>::length(vector2<numericT>& a,vector2<numericT>& b)
{
    numericT dx = a.x - b.x;
    numericT dy = a.y - b.y;
    #ifdef VECTOR2_FLOAT
        return sqrtf(dx * dx + dy * dy);
    #else
        #ifdef VECTOR2_DOUBLE
            return sqrt(dx * dx + dy * dy);
        #else
            #ifdef VECTOR2_LONGDOUBLE
                return sqrtl(dx * dx + dy * dy);
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_SQRT
                        return VECTOR2_CUSTOM_SQRT(dx * dx + dy * dy);
                    #else
                        #error missing definition for VECTOR2_CUSTOM_SQRT, must be defined when VECTOR2_CUSTOM is defined
                    #endif
                #else
                    #warning no preprocessor defined for vector2, some functions are not going to work! , vector2 preprocessors [VECTOR2_FLOAT,VECTOR2_DOUBLE,VECTOR2_LONGDOUBLE,VECTOR2_CUSTOM,(or nothing)]
                #endif
            #endif
        #endif
    #endif
}
template<typename numericT>
numericT vector2<numericT>::det()
{
    #ifdef VECTOR2_FLOAT
        return sqrtf(this->x * this->x + this->y * this->y);
    #else
        #ifdef VECTOR2_DOUBLE
            return sqrt(this->x * this->x + this->y * this->y);
        #else
            #ifdef VECTOR2_LONGDOUBLE
                return sqrtl(this->x * this->x + this->y * this->y);
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_SQRT
                        return VECTOR2_CUSTOM_SQRT(this->x * this->x + this->y * this->y);
                    #else
                        #error missing definition for VECTOR2_CUSTOM_SQRT, must be defined when VECTOR2_CUSTOM is defined
                    #endif
                #else
                    #warning no preprocessor defined for vector2, some functions are not going to work! , vector2 preprocessors [VECTOR2_FLOAT,VECTOR2_DOUBLE,VECTOR2_LONGDOUBLE,VECTOR2_CUSTOM,(or nothing)]
                #endif
            #endif
        #endif
    #endif
}
template<typename numericT>
void vector2<numericT>::det_c_eq()
{
    #ifdef VECTOR2_FLOAT
        numericT r = sqrtf(this->x * this->x + this->y * this->y);
    #else
        #ifdef VECTOR2_DOUBLE
            numericT r = sqrt(this->x * this->x + this->y * this->y);
        #else
            #ifdef VECTOR2_LONGDOUBLE
                numericT r =  sqrtl(this->x * this->x + this->y * this->y);
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_SQRT
                        numericT r = VECTOR2_CUSTOM_SQRT(this->x * this->x + this->y * this->y);
                    #else
                        #error missing definition for VECTOR2_CUSTOM_SQRT, must be defined when VECTOR2_CUSTOM is defined
                    #endif
                #else
                    #warning no preprocessor defined for vector2, some functions are not going to work! , vector2 preprocessors [VECTOR2_FLOAT,VECTOR2_DOUBLE,VECTOR2_LONGDOUBLE,VECTOR2_CUSTOM,(or nothing)]
                #endif
            #endif
        #endif
    #endif
    this->x = r;
    this->y = r;
}
template<typename numericT>
numericT vector2<numericT>::det(vector2<numericT>& a)
{
    #ifdef VECTOR2_FLOAT
        return sqrtf(a.x * a.x + a.y * a.y);
    #else
        #ifdef VECTOR2_DOUBLE
            return sqrt(a.x * a.x + a.y * a.y);
        #else
            #ifdef VECTOR2_LONGDOUBLE
                return sqrtl(a.x * a.x + a.y * a.y);
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_SQRT
                        return VECTOR2_CUSTOM_SQRT(a.x * a.x + a.y * a.y);
                    #else
                        #error missing definition for VECTOR2_CUSTOM_SQRT, must be defined when VECTOR2_CUSTOM is defined
                    #endif
                #else
                    #warning no preprocessor defined for vector2, some functions are not going to work! , vector2 preprocessors [VECTOR2_FLOAT,VECTOR2_DOUBLE,VECTOR2_LONGDOUBLE,VECTOR2_CUSTOM,(or nothing)]
                #endif
            #endif
        #endif
    #endif
}
template<typename numericT>
vector2<numericT> vector2<numericT>::normal()
{
    return this->div(this->det());
}
template<typename numericT>
vector2<numericT> vector2<numericT>::normal(vector2<numericT>& a)
{
    return a.div(a.det());
}
template<typename numericT>
void vector2<numericT>::normalize()
{
    vector2 normal = this->div(this->det());
    this->x = normal.x;
    this->y = normal.y;
}
template<typename numericT>
numericT vector2<numericT>::dot(vector2<numericT>& b)
{
    return this->x * b.x + this->y * b.y;
}
template<typename numericT>
void vector2<numericT>::dot_c_eq(vector2<numericT>& b)
{
    numericT r = this->x * b.x + this->y * b.y;
    this->x = r;
    this->y = r;
}
template<typename numericT>
numericT vector2<numericT>::dot(vector2<numericT>& a,vector2<numericT>& b)
{
    return a.x * b.x + a.y * b.y;
}
template<typename numericT>
void vector2<numericT>::operator=(vector2<numericT>& a)
{
    this->x = a.x;
    this->y = a.y;
}
template<typename numericT>
bool vector2<numericT>::equals(vector2<numericT>& b)
{
    return (this->x == b.x) && (this->y == b.y);
}
template<typename numericT>
bool vector2<numericT>::equals(vector2<numericT>& a,vector2<numericT>& b)
{
    return (a.x == b.x) && (a.y == b.y);
}
template<typename numericT>
bool vector2<numericT>::any_equals(vector2<numericT>& b)
{
    return (this->x == b.x) || (this->y == b.y);
}
template<typename numericT>
bool vector2<numericT>::any_equals(vector2<numericT>& a,vector2<numericT>& b)
{
    return (a.x == b.x) || (a.y == b.y);
}
template<typename numericT>
bool vector2<numericT>::equals_l(vector2<numericT>& a)
{
    return this->det() == a.det();
}
template<typename numericT>
bool vector2<numericT>::equals_l(vector2<numericT>& a,vector2<numericT>& b)
{
    return a.det() == b.det();
}
template<typename numericT>
vector2<numericT> vector2<numericT>::add(numericT b)
{
    return vector2(this->x + b,this->y + b);
}
template<typename numericT>
void vector2<numericT>::add_eq(numericT b)
{
    this->x += b;
    this->y += b;
}
template<typename numericT>
vector2<numericT> vector2<numericT>::add(vector2<numericT>& a,numericT b)
{
    return vector2(a.x + b,a.y + b);
}
template<typename numericT>
vector2<numericT> vector2<numericT>::operator+(numericT b)
{
    return vector2(this->x + b,this->y + b);
}
template<typename numericT>
void vector2<numericT>::operator+=(numericT b)
{
    this->x += b;
    this->y += b;
}
template<typename numericT>
vector2<numericT> vector2<numericT>::sub(numericT b)
{
    return vector2(this->x - b,this->y - b);
}
template<typename numericT>
void vector2<numericT>::sub_eq(numericT b)
{
    this->x -= b;
    this->y -= b;
}
template<typename numericT>
vector2<numericT> vector2<numericT>::sub(vector2<numericT>& a,numericT b)
{
    return vector2(a.x - b,a.y - b);
}
template<typename numericT>
vector2<numericT> vector2<numericT>::operator-(numericT b)
{
    return vector2(this->x - b,this->y - b);
}
template<typename numericT>
void vector2<numericT>::operator-=(numericT b)
{
    this->x -= b;
    this->y -= b;
}
template<typename numericT>
vector2<numericT> vector2<numericT>::mul(numericT b)
{
    return vector2(this->x * b,this->y * b);
}
template<typename numericT>
void vector2<numericT>::mul_eq(numericT b)
{
    this->x *= b;
    this->y *= b;
}
template<typename numericT>
vector2<numericT> vector2<numericT>::mul(vector2<numericT>& a,numericT b)
{
    return vector2(a.x * b,a.y * b);
}
template<typename numericT>
vector2<numericT> vector2<numericT>::operator*(numericT b)
{
    return vector2(this->x * b,this->y * b);
}
template<typename numericT>
void vector2<numericT>::operator*=(numericT b)
{
    this->x *= b;
    this->y *= b;
}
template<typename numericT>
vector2<numericT> vector2<numericT>::div(numericT b)
{
    return vector2(this->x / b,this->y / b);
}
template<typename numericT>
void vector2<numericT>::div_eq(numericT b)
{
    this->x /= b;
    this->y /= b;
}
template<typename numericT>
vector2<numericT> vector2<numericT>::div(vector2<numericT>& a,numericT b)
{
    return vector2(a.x / b,a.y / b);
}
template<typename numericT>
vector2<numericT> vector2<numericT>::operator/(numericT b)
{
    return vector2(this->x / b,this->y / b);
}
template<typename numericT>
void vector2<numericT>::operator/=(numericT b)
{
    this->x /= b;
    this->y /= b;
}
template<typename numericT>
numericT vector2<numericT>::length(numericT b)
{
    numericT dx = this->x - b;
    numericT dy = this->y - b;
    #ifdef VECTOR2_FLOAT
        return sqrtf(dx * dx + dy * dy);
    #else
        #ifdef VECTOR2_DOUBLE
            return sqrt(dx * dx + dy * dy);
        #else
            #ifdef VECTOR2_LONGDOUBLE
                return sqrtl(dx * dx + dy * dy);
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_SQRT
                        return VECTOR2_CUSTOM_SQRT(dx * dx + dy * dy);
                    #else
                        #error missing definition for VECTOR2_CUSTOM_SQRT, must be defined when VECTOR2_CUSTOM is defined
                    #endif
                #else
                    #warning no preprocessor defined for vector2, some functions are not going to work! , vector2 preprocessors [VECTOR2_FLOAT,VECTOR2_DOUBLE,VECTOR2_LONGDOUBLE,VECTOR2_CUSTOM,(or nothing)]
                #endif
            #endif
        #endif
    #endif
}
template<typename numericT>
void vector2<numericT>::length_c_eq(numericT b)
{
    numericT dx = this->x - b;
    numericT dy = this->y - b;
    numericT r;
    #ifdef VECTOR2_FLOAT
        r = sqrtf(dx * dx + dy * dy);
    #else
        #ifdef VECTOR2_DOUBLE
            r = sqrt(dx * dx + dy * dy);
        #else
            #ifdef VECTOR2_LONGDOUBLE
                r = sqrtl(dx * dx + dy * dy);
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_SQRT
                        r = VECTOR2_CUSTOM_SQRT(dx * dx + dy * dy);
                    #else
                        #error missing definition for VECTOR2_CUSTOM_SQRT, must be defined when VECTOR2_CUSTOM is defined
                    #endif
                #else
                    #warning no preprocessor defined for vector2, some functions are not going to work! , vector2 preprocessors [VECTOR2_FLOAT,VECTOR2_DOUBLE,VECTOR2_LONGDOUBLE,VECTOR2_CUSTOM,(or nothing)]
                #endif
            #endif
        #endif
    #endif
    this->x = r;
    this->y = r;
}
template<typename numericT>
void vector2<numericT>::operator=(numericT& a)
{
    this->x = a;
    this->y = a;
}
template<typename numericT>
bool vector2<numericT>::equals(numericT b)
{
    return (this->x == b) && (this->y == b);
}
template<typename numericT>
bool vector2<numericT>::equals(vector2<numericT>& a,numericT b)
{
    return (a.x == b) && (a.y == b);
}
template<typename numericT>
bool vector2<numericT>::any_equals(numericT b)
{
    return (this->x == b) || (this->y == b);
}
template<typename numericT>
bool vector2<numericT>::any_equals(vector2<numericT>& a,numericT b)
{
    return (a.x == b) || (a.y == b);
}
template<typename numericT>
bool vector2<numericT>::isLargerThan_l(vector2<numericT>& b)
{
    return (this->det() > b.det());
}
template<typename numericT>
bool vector2<numericT>::operator>(vector2<numericT>& b)
{
    return this->det() > b.det();
}
template<typename numericT>
bool vector2<numericT>::isLargerThan_l(vector2<numericT>& a,vector2<numericT>& b)
{
    return a.det() > b.det();
}
template<typename numericT>
bool vector2<numericT>::isLargerThanOrEqual_l(vector2<numericT>& b)
{
    return this->det() >= b.det();
}
template<typename numericT>
bool vector2<numericT>::operator>=(vector2<numericT>& b)
{
    return this->det() >= b.det();
}
template<class numericT> 
bool vector2<numericT>::isLargerThanOrEqual_l(vector2<numericT> &a, vector2<numericT> &b)
{
    return a.det() >= b.det();
}
template<typename numericT>
bool vector2<numericT>::isSmallerThan_l(vector2<numericT>& b)
{
    return this->det() < b.det();
}
template<typename numericT>
bool vector2<numericT>::operator<(vector2<numericT>& b)
{
    return this->det() < b.det();
}
template<typename numericT>
bool vector2<numericT>::isSmallerThan_l(vector2<numericT>& a,vector2<numericT>& b)
{
    return a.det() < b.det();
}
template<typename numericT>
bool vector2<numericT>::isSmallerThanOrEqual_l(vector2<numericT>& b)
{
    return this->det() <= b.det();
}
template<typename numericT>
bool vector2<numericT>::operator<=(vector2<numericT>& b)
{
    return this->det() <= b.det();
}
template<typename numericT>
bool vector2<numericT>::isSmallerThanOrEqual_l(vector2<numericT>& a,vector2<numericT>& b)
{
    return a.det() <= b.det();
}