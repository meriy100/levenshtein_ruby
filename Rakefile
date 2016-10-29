require "bundler/gem_tasks"
require "rspec/core/rake_task"
require "rake/extensiontask"

Rake::ExtensionTask.new "levenshtein_ruby" do |ext|
  ext.lib_dir = "lib/levenshtein_ruby"
end

RSpec::Core::RakeTask.new(:spec)

task :default => :spec
