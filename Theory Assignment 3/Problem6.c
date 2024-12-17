#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Weather {
    float temperature;
    float rainfall;
    float windSpeed;
} Weather;

typedef struct Crop {
    char cropType[20];
    int growthStage;
    float expectedYield;
    Weather *weatherForecast;
} Crop;

typedef struct Equipment {
    char equipmentType[20];
    int operationalStatus;
    float fuelLevel;
    char activitySchedule[50];
} Equipment;

typedef struct Sensor {
    float soilNutrients[5];
    float pHLevel;
    int pestActivity;
} Sensor;

typedef struct Field {
    float gpsCoordinates[2];
    float soilHealth[3];
    float moistureLevel;
    Crop *crops;
    Equipment *equipment;
    Sensor *sensors;
    int numCrops;
    int numEquipment;
    int numSensors;
} Field;

typedef struct RegionalHub {
    Field *fields;
    int numFields;
    float aggregateYield;
} RegionalHub;

void initializeFieldMetrics(Field *field, int numCrops, int numEquipment, int numSensors) {
    field->crops = (Crop *)malloc(numCrops * sizeof(Crop));
    field->equipment = (Equipment *)malloc(numEquipment * sizeof(Equipment));
    field->sensors = (Sensor *)malloc(numSensors * sizeof(Sensor));
    field->numCrops = numCrops;
    field->numEquipment = numEquipment;
    field->numSensors = numSensors;

    for (int i = 0; i < numCrops; i++) {
        strcpy(field->crops[i].cropType, "Unknown");
        field->crops[i].growthStage = 0;
        field->crops[i].expectedYield = 0.0;
        field->crops[i].weatherForecast = NULL;
    }

    for (int i = 0; i < numEquipment; i++) {
        strcpy(field->equipment[i].equipmentType, "Unknown");
        field->equipment[i].operationalStatus = 0;
        field->equipment[i].fuelLevel = 0.0;
        strcpy(field->equipment[i].activitySchedule, "Not Scheduled");
    }

    for (int i = 0; i < numSensors; i++) {
        memset(field->sensors[i].soilNutrients, 0, 5 * sizeof(float));
        field->sensors[i].pHLevel = 7.0;
        field->sensors[i].pestActivity = 0;
    }
}

void freeFieldMetrics(Field *field) {
    for (int i = 0; i < field->numCrops; i++) {
        if (field->crops[i].weatherForecast != NULL) {
            free(field->crops[i].weatherForecast);
        }
    }
    free(field->crops);
    free(field->equipment);
    free(field->sensors);
}

void displayFieldDetails(Field *field) {
    for (int i = 0; i < field->numCrops; i++) {
        printf("Crop Type: %s, Growth Stage: %d, Expected Yield: %.2f\n", field->crops[i].cropType, field->crops[i].growthStage, field->crops[i].expectedYield);
        if (field->crops[i].weatherForecast != NULL) {
            printf("Weather Forecast: Temperature: %.2f°C, Rainfall: %.2fmm, Wind Speed: %.2f km/h\n", field->crops[i].weatherForecast->temperature, field->crops[i].weatherForecast->rainfall, field->crops[i].weatherForecast->windSpeed);
        }
    }
    
    printf("GPS Coordinates: [%.2f, %.2f]\n", field->gpsCoordinates[0], field->gpsCoordinates[1]);
    printf("Soil Health: Organic Matter: %.2f, pH Level: %.2f, Soil Texture: %.2f\n", field->soilHealth[0], field->soilHealth[1], field->soilHealth[2]);
    printf("Moisture Level: %.2f%%\n", field->moistureLevel);

    for (int i = 0; i < field->numEquipment; i++) {
        printf("Equipment Type: %s, Operational Status: %d, Fuel Level: %.2f, Activity Schedule: %s\n", field->equipment[i].equipmentType, field->equipment[i].operationalStatus, field->equipment[i].fuelLevel, field->equipment[i].activitySchedule);
    }

    for (int i = 0; i < field->numSensors; i++) {
        printf("Soil Sensor %d: pH Level: %.2f, Pest Activity: %d\n", i + 1, field->sensors[i].pHLevel, field->sensors[i].pestActivity);
    }
}

int main() {
    int numFields = 2;
    Field *fields = (Field *)malloc(numFields * sizeof(Field));

    for (int i = 0; i < numFields; i++) {
        initializeFieldMetrics(&fields[i], 3, 2, 4);
    }

    strcpy(fields[0].crops[0].cropType, "Wheat");
    fields[0].crops[0].expectedYield = 100.5;
    fields[0].crops[0].weatherForecast = (Weather *)malloc(sizeof(Weather));
    fields[0].crops[0].weatherForecast->temperature = 22.5;
    fields[0].crops[0].weatherForecast->rainfall = 50.0;
    fields[0].crops[0].weatherForecast->windSpeed = 15.5;

    displayFieldDetails(&fields[0]);

    for (int i = 0; i < numFields; i++) {
        freeFieldMetrics(&fields[i]);
    }
    free(fields);

    return 0;
}
