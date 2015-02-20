require 'sinatra'
require 'json'
require 'ruby_spark'
require './env' if File.exists?('env.rb')

RubySpark.configuration do |config|
  config.access_token = ENV['ACCESS_TOKEN']
  config.timeout      = 10000#.seconds # defaults to 30 seconds
end

 core = RubySpark::Core.new("__YourCoreName__")

post '/' do
  core.function("pushed", "foo")
  push = JSON.parse(request.body.read)
  return "I got some JSON: #{push.inspect}"
end

get '/' do
  core.function("pushed", "foo")
  return core.info.inspect
end
