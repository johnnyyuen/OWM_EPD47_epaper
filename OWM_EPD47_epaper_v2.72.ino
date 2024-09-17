// Due to the license issue, I will just post the fix part. For the rest of code, please go to the original GitHub link ( I think you should have it already )
.
.
.
.
.
.
// Update the singletime to weather
while ((RxWeather == false || RxForecast == false) && Attempts <= 2) { // Try up-to 2 time for Weather and Forecast data
  if (RxWeather  == false) RxWeather  = obtainWeatherData(client, "weather");
  if (RxForecast == false) RxForecast = obtainWeatherData(client, "forecast");
  Attempts++;
}
.
.
.
.
.

// Update the field mapping
if (Type == "weather") {
    // All Serial.println statements are for diagnostic purposes and some are not required, remove if not needed with //
    WxConditions[0].High        = -50; // Minimum forecast low
    WxConditions[0].Low         = 50;  // Maximum Forecast High
    WxConditions[0].FTimezone   = doc["timezone_offset"]; // "0"
    //JsonObject current = doc["current"];
    WxConditions[0].Sunrise     = doc["sys"]["sunrise"];
    WxConditions[0].Sunset      = doc["sys"]["sunset"];
    WxConditions[0].Temperature = doc["main"]["temp"];
    WxConditions[0].FeelsLike   = doc["main"]["feels_like"];
    WxConditions[0].Pressure    = doc["main"]["pressure"]; 
    WxConditions[0].Humidity    = doc["main"]["humidity"];
    WxConditions[0].DewPoint    = doc["dew_point"];
    WxConditions[0].UVI         = "" //doc["uvi"];
    WxConditions[0].Cloudcover  = doc["clouds"]["all"];
    WxConditions[0].Visibility  = doc["visibility"];
    WxConditions[0].Windspeed   = doc["wind"]["speed"];
    WxConditions[0].Winddir     = doc["wind"]["deg"];
    JsonObject current_weather  = doc["weather"][0];
    String Description = current_weather["description"];                           // "scattered clouds"
    String Icon        = current_weather["icon"];                                  // "01n"
    WxConditions[0].Forecast0   = Description;
    WxConditions[0].Icon        = Icon;
  }

if (Type == "forecast") {
   .
.
.
.
      WxForecast[r].Icon              = (const char*)list[r]["weather"][0]["icon"];
.
.
.
.
.

      }
    }
