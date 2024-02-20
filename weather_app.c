#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
/**
 * This is an app to diplay the weather conditions of a given city
 * The app uses an API and url to access a free weather site to call 
 * this information.
 */

/* This is where the Stormglass' actual OpenWeatherMap API key goes */
#define API_KEY "f511eca8-c0f8-11ee-84d9-0242ac130002-f511ed16-c0f8-11ee-84d9-0242ac130002"
#define API_URL "http://api.stormglass.io/data/v2/weather?q=%s&appid=%s"

/* Structure to hold the HTTP response data */
typedef struct {
    char *data;
    size_t size;
} MemoryStruct;

/* Callback function to handle writing HTTP response data */
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) 
{
	size_t realsize = size * nmemb;
	MemoryStruct *mem = (MemoryStruct *)userp;
	
	mem->data = realloc(mem->data, mem->size + realsize + 1);
	if (mem->data == NULL) 
	{
		fprintf(stderr, "Memory allocation error\n");
		return (0);
	}
	
	memcpy(&(mem->data[mem->size]), contents, realsize);
	mem->size += realsize;
	mem->data[mem->size] = '\0';
	
	return (realsize);
}

/* Function to get weather information for a given city */
void get_weather(char *city) 
{
	CURL *curl;
	CURLcode res;
	
	MemoryStruct chunk;
	chunk.data = malloc(1);
	chunk.size = 0;
	
	/* Build the API URL with the city and API key */
	char url[256];
	sprintf(url, API_URL, city, API_KEY);
	
	/* Initialize the libcurl library */
	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();
	
	if (curl) 
	{
		/* Set the URL to fetch */
		curl_easy_setopt(curl, CURLOPT_URL, url);
		
		/* Set the callback function to handle response data */
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
		
		/* Perform the HTTP request */
		res = curl_easy_perform(curl);
		
		/* Check for errors during the HTTP request */
		if (res != CURLE_OK) 
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		} 
		else 
		{
			/* Print the weather information for the given city */
			printf("Weather information for %s:\n%s\n", city, chunk.data);
		}
		
		/* Cleanup resources */
		curl_easy_cleanup(curl);
		free(chunk.data);
	}
	
	/* Cleanup global libcurl resources */
	curl_global_cleanup();
}

int main(int argc, char *argv[]) 
{
	/* Check if the correct number of command-line arguments is provided */
	if (argc != 2) 
	{
		fprintf(stderr, "Usage: %s <city>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	
	/* Call the function to get weather information for the specified city */
	get_weather(argv[1]);
	
	return (EXIT_SUCCESS);
}
