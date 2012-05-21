/*!
 @file bma180.h
 @brief Geting information of accelometer 
 @author Viktor Green
 @date April 1 2012
 */

#if defined __cplusplus
extern "C" {
#endif

    /*!
     @brief Initializing the accelometer
     */
    void bma180_initialize(void);
    /*!
     @brief Geting Acceleration in X-axis 
     @param float bias: will be added to actual value of accelormeter
     @return float Current acceleration
     */
    float getXAccel(float);
    /*!
     @brief Calculating Bias to compansate angled accelerometer 
     @return float bias
     */
    float calcXBias(void);


#if defined __cplusplus
}
#endif
