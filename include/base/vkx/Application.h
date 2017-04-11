#pragma once

#include <base/vkx/DeviceInfo.h>
#include <base/vkx/QueueManager.h>

#include <vulkan/vulkan.hpp>

#include <string>
#include <vector>

namespace vkx {
class Application
{
  public:
    Application(const std::string& name, bool debugMode);
    Application(const Application&) = delete;
    ~Application();

    Application& operator=(const Application&) = delete;

    const std::string& name() const;
    const vk::Instance& instance() const;
    const vk::PhysicalDevice& physicalDevice() const;
    const vk::Device& device() const;
    const vkx::DeviceInfo& deviceInfo() const;
    const vkx::QueueManager& queues() const;

  private:
    vk::Instance createInstance(const std::vector<const char*>& layers);
    vkx::DeviceInfo selectPhysicalDevice(const std::vector<vk::PhysicalDevice>& physicalDevices);
    vk::Device createDevice();

    void destroyDevice();
    void destroyInstance();

    vk::PhysicalDevice choosePhysicalDevice(const std::vector<vk::PhysicalDevice>& physicalDevices);

    std::string _name;
    vk::Instance _instance;
    vkx::DeviceInfo _deviceInfo;
    vk::Device _device;
    vkx::QueueManager _queueManager;
};
}
