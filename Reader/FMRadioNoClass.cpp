#include <map>

void SetDevicePower(double powerLevel);

struct FMRadio {
    double frequency;
    int volume;
    std::map<int, double> presets;
};

void TuneReceiver(FMRadio radio) {
    double powerLevel = (radio.frequency - 87.5) / (108.0 - 87.5);
    SetDevicePower(powerLevel);
}

void LoadPreset(FMRadio& radio, int preset) {
    std::map<int, double>::iterator itr = radio.presets.find(preset);
    if (itr == radio.presets.end())
        return;
    radio.frequency = itr->second;
}
