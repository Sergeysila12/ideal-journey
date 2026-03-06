
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <algorithm>

class ADevice
{
protected:
std::string ID;
public:
	ADevice()
	{ }
	virtual void turnOn() = 0;
	virtual void turnOff() = 0;
	virtual std::string getData() = 0;
	virtual std::string getID() = 0;
	virtual ~ADevice(){ }
};

class SmartLight : public ADevice
{
private:
	std::string name;
	
public:
	
	void turnOn() override
	{
		std::cout << "Device: " << name << " on\n";
	}
	void turnOff() override
	{ }
	SmartLight(const std:: string& name): ADevice()
	{
		settingLight(name);
	}
	void LightReceiver(const ADevice& R)
	{

	}
	void settingLight(const std::string& name)
	{
		this->name = name;
		this->ID = "1A";
	}
	std::string getData() override
	{
		return name;
	}
	std::string getID() override
	{
		return ID;
	}
	~SmartLight() override
	{ }
};
class Thermostat : public ADevice
{
private:
	std::string name;

public:
	void turnOn() override
	{
		std::cout << "Device: " << name << " on\n";
	}
	void turnOff() override
	{
	}
	Thermostat(const std::string& name) : ADevice()
	{
		settingTherm(name);
	}
	void settingTherm(const std::string& name)
	{
		this->name = name;
		this->ID = "2F";
	}
	std::string getData() override
	{
		return name;
	}
	std::string getID() override
	{
		return ID;
	}
	~Thermostat() override {}
};
class MotionSensor : public ADevice
{
private:
	std::string name;
//	std::string ID = "7L";
public:
	void turnOn() override
	{
		std::cout << "Device: " << name << " on\n";
	}
	void turnOff() override
	{
	}
	MotionSensor(const std::string& name) : ADevice()
	{
		settingSensor(name);
	}
	void settingSensor(const std::string& name)
	{
		this->name = name;
		this->ID = "7L";
	}
	std::string getData() override
	{
		return name;
	}
	std::string getID() override
	{
		return ID;
	}
	~MotionSensor() override {}
};

class SmartHome //: public ADevice
{
private:
	std::vector<std::shared_ptr<ADevice>> V_Device;
	std::string name;
public:
	SmartHome(const SmartHome&) = delete;
	SmartHome& operator=(const SmartHome&) = delete;
	SmartHome(SmartHome&&) = default;
	SmartHome& operator=(SmartHome&&) = default;

	SmartHome(const std::string& name)
	{
		settingName(name);
	}
	void settingVector( const std::shared_ptr<ADevice > &S)
	{
		V_Device.push_back(S);
	}
	void settingName(const std::string& name)
	{
		this->name = name;
	}
	ADevice& getDevice(const std::string& id)
	{
		for (const  auto& device: V_Device)
		{
			if (device->getID() == id)
			{
				return *device;
			}
		}
		throw std::out_of_range ("Device wasn't finded!");
	}
	void turnOnAllDevices()
	{
		std::for_each(V_Device.begin(), V_Device.end(), [](const std::shared_ptr<ADevice>& device)
			{if (device) device->turnOn();});

	}
	void Show()
	{
		std::cout << "Smart Home: " << name << "\n";
		std::cout << "Device: " << "\n";

		for (const auto& Device: V_Device)
		{
			std::cout << Device->getData() << "\n";
		}
	}
};




int main()
{
	std::shared_ptr<ADevice > Therm_ptr{ std::make_shared<Thermostat>("Temperature_regulator") };
	std::shared_ptr<ADevice > Light_ptr{ std::make_shared<SmartLight>("Street_lamp") };
	std::shared_ptr<ADevice > MoSense_ptr{ std::make_shared<MotionSensor>("Sence_detector") };
	
	SmartHome SM1("Green_Roof");
	SM1.settingVector(Therm_ptr);
	SM1.settingVector(Light_ptr);
	SM1.settingVector(MoSense_ptr);
	SM1.Show();
	std::string ID;
	std::cout << "Input ID Device" << "\n";
	std::cin >> ID;
	try
	{
		SM1.getDevice(ID);
	}
	catch (const std::out_of_range & a )
	{
		std::cout << a.what();
	}
	catch (...)
	{
		std::cout << "  //-//-//   ";
	}
	SM1.turnOnAllDevices();

  
}
