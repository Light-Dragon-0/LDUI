#include "vector2.hpp"
/*
nothing (default)
#define VECTOR2_FLOAT
#define VECTOR2_DOUBLE 
#define VECTOR2_LONGDOUBLE
#define VECTOR2_CUSTOM requires def [VECTOR2_CUSTOM_FLOOR,VECTOR2_CUSTOM_ROUND,VECTOR2_CUSTOM_CEIL,VECTOR2_CUSTOM_SQRT]
*/
template<typename componentT>
vector2<componentT>::vector2()
{
    this->x = componentT();
    this->y = componentT();
}
template<typename componentT>
vector2<componentT>::vector2(componentT value)
{
    this->x = value;
    this->y = value;
}
template<typename componentT>
vector2<componentT>::vector2(componentT x,componentT y)
{
    this->x = x;
    this->y = y;
}
template<typename componentT>
vector2<componentT>::vector2(vector2<componentT>& copy)
{
    this->x = copy.x;
    this->y = copy.y;
}
template<typename componentT>
vector2<componentT> vector2<componentT>::add(vector2<componentT>& b)
{
    return vector2(this->x + b.x, this->y + b.y);
}
template<typename componentT>
void vector2<componentT>::add_eq(vector2<componentT>& b)
{
    this->x += b.x;
    this->y += b.y;
}
template<typename componentT>
vector2<componentT> vector2<componentT>::add(vector2<componentT>& a,vector2<componentT>& b)
{
    return vector2(a.x + b.x, a.y + b.y);
}
template<typename componentT>
vector2<componentT> vector2<componentT>::operator+(vector2<componentT>& b)
{
    return vector2(this->x + b.x, this->y + b.y);
}
template<typename componentT>
void vector2<componentT>::operator+=(vector2<componentT>& b)
{
    this->x += b.x;
    this->y += b.y;
}
template<typename componentT>
vector2<componentT> vector2<componentT>::sub(vector2<componentT>& b)
{
    return vector2<componentT>(this->x - b.x,this->y - b.y);
}
template<typename componentT>
void vector2<componentT>::sub_eq(vector2<componentT>& b)
{
    this->x -= b.x;
    this->y -= b.y;
}
template<typename componentT>
vector2<componentT> vector2<componentT>::sub(vector2<componentT>& a,vector2<componentT>& b)
{
    return vector2<componentT>(a.x - b.x,a.y - b.y);
}
template<typename componentT>
vector2<componentT> vector2<componentT>::operator-(vector2<componentT>& b)
{
    return vector2(this->x - b.x,this->y - b.y);
}
template<typename componentT>
void vector2<componentT>::operator-=(vector2<componentT>& b)
{
    this->x -= b.x;
    this->y -= b.y;
}
template<typename componentT>
vector2<componentT> vector2<componentT>::mul(vector2<componentT>& b)
{
    return vector2(this->x * b.x,this->y * b.y);
}
template<typename componentT>
void vector2<componentT>::mul_eq(vector2<componentT>& b)
{
    this->x *= b.x;
    this->y *= b.y;
}
template<typename componentT>
vector2<componentT> vector2<componentT>::mul(vector2<componentT>& a,vector2<componentT>& b)
{
    return vector2(a.x * b.x,a.y * b.y);
}
template<typename componentT>
vector2<componentT> vector2<componentT>::operator*(vector2<componentT>& b)
{
    return vector2(this->x * b.x,this->y * b.y);
}
template<typename componentT>
void vector2<componentT>::operator*=(vector2<componentT>& b)
{
    this->x *= b.x;
    this->y *= b.y;
}
template<typename componentT>
vector2<componentT> vector2<componentT>::div(vector2<componentT>& b)
{
    return vector2(this->x / b.x,this->y / b.y);
}
template<typename componentT>
void vector2<componentT>::div_eq(vector2<componentT>& b)
{
    this->x /= b.x;
    this->y /= b.y;
}
template<typename componentT>
vector2<componentT> vector2<componentT>::div(vector2<componentT>& a,vector2<componentT>& b)
{
    return vector2(a.x / b.x, a.y / b.y);
}
template<typename componentT>
vector2<componentT> vector2<componentT>::operator/(vector2<componentT>& b)
{
    return vector2(this->x / b.x, this->y / b.y);
}
template<typename componentT>
void vector2<componentT>::operator/=(vector2<componentT>& b)
{
    this->x /= b.x;
    this->y /= b.y;
}
template<typename componentT>
vector2<componentT> vector2<componentT>::floor_c()
{
    #ifdef VECTOR2_FLOAT
        vector2<componentT> vec;
        vec.x = floorf(this->x);
        vec.y = floorf(this->y);
        return vec;
    #else
        #ifdef VECTOR2_DOUBLE
            vector2<componentT> vec;
            vec.x = floor(this->x);
            vec.y = floor(this->y);
            return vec;
        #else
            #ifdef VECTOR2_LONGDOUBLE
                vector2<componentT> vec;
                vec.x = floorl(this->x);
                vec.y = floorl(this->y);
                return vec;
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_FLOOR
                        vector2<componentT> vec;
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
template<typename componentT>
void vector2<componentT>::floor_c_eq()
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
template<typename componentT>
vector2<componentT> vector2<componentT>::floor_c(vector2<componentT>& a)
{
    #ifdef VECTOR2_FLOAT
        vector2<componentT> vec;
        vec.x = floorf(a.x);
        vec.y = floorf(a.y);
        return vec;
    #else
        #ifdef VECTOR2_DOUBLE
            vector2<componentT> vec;
            vec.x = floor(a.x);
            vec.y = floor(a.y);
            return vec;
        #else
            #ifdef VECTOR2_LONGDOUBLE
                vector2<componentT> vec;
                vec.x = floorl(a.x);
                vec.y = floorl(a.y);
                return vec;
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_FLOOR
                        vector2<componentT> vec;
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
template<typename componentT>
vector2<componentT> vector2<componentT>::round_c()
{
    #ifdef VECTOR2_FLOAT
        vector2<componentT> vec;
        vec.x = roundf(this->x);
        vec.y = roundf(this->y);
        return vec;
    #else
        #ifdef VECTOR2_DOUBLE
            vector2<componentT> vec;
            vec.x = round(this->x);
            vec.y = round(this->y);
            return vec;
        #else
            #ifdef VECTOR2_LONGDOUBLE
                vector2<componentT> vec;
                vec.x = roundl(this->x);
                vec.y = roundl(this->y);
                return vec;
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_ROUND
                        vector2<componentT> vec;
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
template<typename componentT>
void vector2<componentT>::round_c_eq()
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
template<typename componentT>
vector2<componentT> vector2<componentT>::round_c(vector2<componentT>& a)
{
    
    #ifdef VECTOR2_FLOAT
        vector2<componentT> vec;
        vec.x = roundf(a.x);
        vec.y = roundf(a.y);
        return vec;
    #else
        #ifdef VECTOR2_DOUBLE
            vector2<componentT> vec;
            vec.x = round(a.x);
            vec.y = round(a.y);
            return vec;
        #else
            #ifdef VECTOR2_LONGDOUBLE
                vector2<componentT> vec;
                vec.x = roundl(a.x);
                vec.y = roundl(a.y);
                return vec;
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_ROUND
                        vector2<componentT> vec;
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
template<typename componentT>
vector2<componentT> vector2<componentT>::ceil_c()
{
    #ifdef VECTOR2_FLOAT
        vector2<componentT> vec;
        vec.x = ceilf(this->x);
        vec.y = ceilf(this->y);
        return vec;
    #else
        #ifdef VECTOR2_DOUBLE
            vector2<componentT> vec;
            vec.x = ceil(this->x);
            vec.y = ceil(this->y);
            return vec;
        #else
            #ifdef VECTOR2_LONGDOUBLE
                vector2<componentT> vec;
                vec.x = ceill(this->x);
                vec.y = ceill(this->y);
                return vec;
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_CEIL
                        vector2<componentT> vec;
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
template<typename componentT>
void vector2<componentT>::ceil_c_eq()
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
template<typename componentT>
vector2<componentT> vector2<componentT>::ceil_c(vector2<componentT>& a)
{
    #ifdef VECTOR2_FLOAT
        vector2<componentT> vec;
        vec.x = ceilf(a.x);
        vec.y = ceilf(a.y);
        return vec;
    #else
        #ifdef VECTOR2_DOUBLE
            vector2<componentT> vec;
            vec.x = ceil(a.x);
            vec.y = ceil(a.y);
            return vec;
        #else
            #ifdef VECTOR2_LONGDOUBLE
                vector2<componentT> vec;
                vec.x = ceill(a.x);
                vec.y = ceill(a.y);
                return vec;
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_CEIL
                        vector2<componentT> vec;
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
template<typename componentT>
vector2<componentT> vector2<componentT>::min_c(vector2<componentT>& b)
{
    return vector2(((this->x < b.x)?this->x:b.x),((this->y < b.y)?this->y:b.y));
} //returns the min of each component
template<typename componentT>
void vector2<componentT>::min_c_eq(vector2<componentT>& b)
{
    this->x = ((this->x < b.x)?this->x:b.x);
    this->y = ((this->y < b.y)?this->y:b.y);
}
template<typename componentT>
vector2<componentT> vector2<componentT>::min_c(vector2<componentT>& a,vector2<componentT>& b)
{
    return vector2(((a.x < b.x)?a.x:b.x),((a.y < b.y)?a.y:b.y));
}
template<typename componentT>
vector2<componentT> vector2<componentT>::min_l(vector2<componentT>& b)
{
    //there might be a way to optmize this ... unconfirmed solution
    if(this->det() < b.det())
        return this;
    else 
        return b;
} //returns the vector with min length
template<typename componentT>
void vector2<componentT>::min_l_eq(vector2<componentT>& b)
{
    if(b.det() < this->det())
        this = b;
}
template<typename componentT>
vector2<componentT> vector2<componentT>::min_l(vector2<componentT>& a,vector2<componentT>& b)
{
    if(a.det() < b.det())
        return a;
    else
        return b;
}
template<typename componentT>
vector2<componentT> vector2<componentT>::max_c(vector2<componentT>& b)
{
    return vector2(((this->x > b.x)?this->x:b.x),((this->y > b.y)?this->y:b.y));
} //returns the max of each component
template<typename componentT>
void vector2<componentT>::max_c_eq(vector2<componentT>& b)
{
    this->x = ((this->x > b.x)?this->x:b.x);
    this->y = ((this->y > b.y)?this->y:b.y);
}
template<typename componentT>
vector2<componentT> vector2<componentT>::max_c(vector2<componentT>& a,vector2<componentT>& b)
{
    return vector2(((a.x > b.x)?a.x:b.x),((a.y > b.y)?a.y:b.y));
}
template<typename componentT>
vector2<componentT> vector2<componentT>::max_l(vector2<componentT>& b)
{
    if(this->det() > b.det())
        return this;
    else
        return b;
} //returns the vector with max length
template<typename componentT>
void vector2<componentT>::max_l_eq(vector2<componentT>& b)
{
    if(this->det() < b.det())
        this = b;
}
template<typename componentT>
vector2<componentT> vector2<componentT>::max_l(vector2<componentT>& a,vector2<componentT>& b)
{
    if(a.det() < b.det())
        return b;
    else
        return a;
}
template<typename componentT>
componentT vector2<componentT>::length(vector2<componentT>& b)
{
    componentT dx = this->x - b.x;
    componentT dy = this->y - b.y;
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
template<typename componentT>
void vector2<componentT>::length_c_eq(vector2<componentT>& b)
{
    componentT dx = this->x - b.x;
    componentT dy = this->y - b.y;
    componentT r;
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
template<typename componentT>
componentT vector2<componentT>::length(vector2<componentT>& a,vector2<componentT>& b)
{
    componentT dx = a.x - b.x;
    componentT dy = a.y - b.y;
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
template<typename componentT>
componentT vector2<componentT>::det()
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
template<typename componentT>
void vector2<componentT>::det_c_eq()
{
    #ifdef VECTOR2_FLOAT
        componentT r = sqrtf(this->x * this->x + this->y * this->y);
    #else
        #ifdef VECTOR2_DOUBLE
            componentT r = sqrt(this->x * this->x + this->y * this->y);
        #else
            #ifdef VECTOR2_LONGDOUBLE
                componentT r =  sqrtl(this->x * this->x + this->y * this->y);
            #else 
                #ifdef VECTOR2_CUSTOM
                    #ifdef VECTOR2_CUSTOM_SQRT
                        componentT r = VECTOR2_CUSTOM_SQRT(this->x * this->x + this->y * this->y);
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
template<typename componentT>
componentT vector2<componentT>::det(vector2<componentT>& a)
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
template<typename componentT>
vector2<componentT> vector2<componentT>::normal()
{
    return this->div(this->det());
}
template<typename componentT>
vector2<componentT> vector2<componentT>::normal(vector2<componentT>& a)
{
    return a.div(a.det());
}
template<typename componentT>
void vector2<componentT>::normalize()
{
    vector2 normal = this->div(this->det());
    this->x = normal.x;
    this->y = normal.y;
}
template<typename componentT>
componentT vector2<componentT>::dot(vector2<componentT>& b)
{
    return this->x * b.x + this->y * b.y;
}
template<typename componentT>
void vector2<componentT>::dot_c_eq(vector2<componentT>& b)
{
    componentT r = this->x * b.x + this->y * b.y;
    this->x = r;
    this->y = r;
}
template<typename componentT>
componentT vector2<componentT>::dot(vector2<componentT>& a,vector2<componentT>& b)
{
    return a.x * b.x + a.y * b.y;
}
template<typename componentT>
void vector2<componentT>::operator=(vector2<componentT>& a)
{
    this->x = a.x;
    this->y = a.y;
}
template<typename componentT>
bool vector2<componentT>::equals(vector2<componentT>& b)
{
    return (this->x == b.x) && (this->y == b.y);
}
template<typename componentT>
bool vector2<componentT>::equals(vector2<componentT>& a,vector2<componentT>& b)
{
    return (a.x == b.x) && (a.y == b.y);
}
template<typename componentT>
bool vector2<componentT>::any_equals(vector2<componentT>& b)
{
    return (this->x == b.x) || (this->y == b.y);
}
template<typename componentT>
bool vector2<componentT>::any_equals(vector2<componentT>& a,vector2<componentT>& b)
{
    return (a.x == b.x) || (a.y == b.y);
}
template<typename componentT>
bool vector2<componentT>::equals_l(vector2<componentT>& a)
{
    return this->det() == a.det();
}
template<typename componentT>
bool vector2<componentT>::equals_l(vector2<componentT>& a,vector2<componentT>& b)
{
    return a.det() == b.det();
}
template<typename componentT>
vector2<componentT> vector2<componentT>::add(componentT b)
{
    return vector2(this->x + b,this->y + b);
}
template<typename componentT>
void vector2<componentT>::add_eq(componentT b)
{
    this->x += b;
    this->y += b;
}
template<typename componentT>
vector2<componentT> vector2<componentT>::add(vector2<componentT>& a,componentT b)
{
    return vector2(a.x + b,a.y + b);
}
template<typename componentT>
vector2<componentT> vector2<componentT>::operator+(componentT b)
{
    return vector2(this->x + b,this->y + b);
}
template<typename componentT>
void vector2<componentT>::operator+=(componentT b)
{
    this->x += b;
    this->y += b;
}
template<typename componentT>
vector2<componentT> vector2<componentT>::sub(componentT b)
{
    return vector2(this->x - b,this->y - b);
}
template<typename componentT>
void vector2<componentT>::sub_eq(componentT b)
{
    this->x -= b;
    this->y -= b;
}
template<typename componentT>
vector2<componentT> vector2<componentT>::sub(vector2<componentT>& a,componentT b)
{
    return vector2(a.x - b,a.y - b);
}
template<typename componentT>
vector2<componentT> vector2<componentT>::operator-(componentT b)
{
    return vector2(this->x - b,this->y - b);
}
template<typename componentT>
void vector2<componentT>::operator-=(componentT b)
{
    this->x -= b;
    this->y -= b;
}
template<typename componentT>
vector2<componentT> vector2<componentT>::mul(componentT b)
{
    return vector2(this->x * b,this->y * b);
}
template<typename componentT>
void vector2<componentT>::mul_eq(componentT b)
{
    this->x *= b;
    this->y *= b;
}
template<typename componentT>
vector2<componentT> vector2<componentT>::mul(vector2<componentT>& a,componentT b)
{
    return vector2(a.x * b,a.y * b);
}
template<typename componentT>
vector2<componentT> vector2<componentT>::operator*(componentT b)
{
    return vector2(this->x * b,this->y * b);
}
template<typename componentT>
void vector2<componentT>::operator*=(componentT b)
{
    this->x *= b;
    this->y *= b;
}
template<typename componentT>
vector2<componentT> vector2<componentT>::div(componentT b)
{
    return vector2(this->x / b,this->y / b);
}
template<typename componentT>
void vector2<componentT>::div_eq(componentT b)
{
    this->x /= b;
    this->y /= b;
}
template<typename componentT>
vector2<componentT> vector2<componentT>::div(vector2<componentT>& a,componentT b)
{
    return vector2(a.x / b,a.y / b);
}
template<typename componentT>
vector2<componentT> vector2<componentT>::operator/(componentT b)
{
    return vector2(this->x / b,this->y / b);
}
template<typename componentT>
void vector2<componentT>::operator/=(componentT b)
{
    this->x /= b;
    this->y /= b;
}
template<typename componentT>
componentT vector2<componentT>::length(componentT b)
{
    componentT dx = this->x - b;
    componentT dy = this->y - b;
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
template<typename componentT>
void vector2<componentT>::length_c_eq(componentT b)
{
    componentT dx = this->x - b;
    componentT dy = this->y - b;
    componentT r;
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
template<typename componentT>
void vector2<componentT>::operator=(componentT& a)
{
    this->x = a;
    this->y = a;
}
template<typename componentT>
bool vector2<componentT>::equals(componentT b)
{
    return (this->x == b) && (this->y == b);
}
template<typename componentT>
bool vector2<componentT>::equals(vector2<componentT>& a,componentT b)
{
    return (a.x == b) && (a.y == b);
}
template<typename componentT>
bool vector2<componentT>::any_equals(componentT b)
{
    return (this->x == b) || (this->y == b);
}
template<typename componentT>
bool vector2<componentT>::any_equals(vector2<componentT>& a,componentT b)
{
    return (a.x == b) || (a.y == b);
}
template<typename componentT>
bool vector2<componentT>::isLargerThan_l(vector2<componentT>& b)
{
    return (this->det() > b.det());
}
template<typename componentT>
bool vector2<componentT>::operator>(vector2<componentT>& b)
{
    return this->det() > b.det();
}
template<typename componentT>
bool vector2<componentT>::isLargerThan_l(vector2<componentT>& a,vector2<componentT>& b)
{
    return a.det() > b.det();
}
template<typename componentT>
bool vector2<componentT>::isLargerThanOrEqual_l(vector2<componentT>& b)
{
    return this->det() >= b.det();
}
template<typename componentT>
bool vector2<componentT>::operator>=(vector2<componentT>& b)
{
    return this->det() >= b.det();
}
template<class componentT> 
bool vector2<componentT>::isLargerThanOrEqual_l(vector2<componentT> &a, vector2<componentT> &b)
{
    return a.det() >= b.det();
}
template<typename componentT>
bool vector2<componentT>::isSmallerThan_l(vector2<componentT>& b)
{
    return this->det() < b.det();
}
template<typename componentT>
bool vector2<componentT>::operator<(vector2<componentT>& b)
{
    return this->det() < b.det();
}
template<typename componentT>
bool vector2<componentT>::isSmallerThan_l(vector2<componentT>& a,vector2<componentT>& b)
{
    return a.det() < b.det();
}
template<typename componentT>
bool vector2<componentT>::isSmallerThanOrEqual_l(vector2<componentT>& b)
{
    return this->det() <= b.det();
}
template<typename componentT>
bool vector2<componentT>::operator<=(vector2<componentT>& b)
{
    return this->det() <= b.det();
}
template<typename componentT>
bool vector2<componentT>::isSmallerThanOrEqual_l(vector2<componentT>& a,vector2<componentT>& b)
{
    return a.det() <= b.det();
}