import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.Reducer;


//CardsHadoop20 will add up the numbers of each card suit independently from numbers 2 through 10 and ignore the cards with no number.
//The cards with no number are Ace, Jack, Queen, King, and Joker.
//When adding up the numerical cards using 100 deck of cards, the resulting sum for each independent suit is 5400.
//When adding up the numerical cards using 5 deck of cards, the resulting sum for each independent suit is 270.



public class CardsHadoop20
{



	



	

public static class CardMapper extends Mapper<LongWritable, Text, Text, IntWritable> {



	private static Pattern inputPattern = Pattern.compile("(.*) (\\d*)");

	 private Text word =new Text();

	@Override

	public void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {

		String inputLine = value.toString();



		Matcher inputMatch = inputPattern.matcher(inputLine);



		// Use regex to throw out Jacks, Queens, Kings, Aces and Jokers

		if (inputMatch.matches()) {

			// Normalize inconsistent case for card suits

			String cardSuit = inputMatch.group(1).toLowerCase();

			int cardValue = Integer.parseInt(inputMatch.group(2));
             word.set(new Text(cardSuit));


			context.write(word, new IntWritable(cardValue));

		}

	}

}


public static class CardTotalReducer extends Reducer<Text, IntWritable, Text, IntWritable> {

	private IntWritable result=new IntWritable();

	@Override

	public void reduce(Text key, Iterable<IntWritable> values, Context context) throws IOException,

			InterruptedException {

		int sum = 0;



		// Go through all values to sum up card values for a card suit

		for (IntWritable value : values) {
			

			sum=sum+value.get();

		}


        result.set(sum);
		context.write(key, result);

	}

}
public static void main(String[] args) throws Exception
{
	 


	



	 Configuration conf=new Configuration();
	 Job job=Job.getInstance(conf, "CardsHadoop20");


	job.setJarByClass(CardsHadoop20.class);




	FileInputFormat.setInputPaths(job, new Path(args[0]));

	FileOutputFormat.setOutputPath(job, new Path(args[1]));



	job.setMapperClass(CardMapper.class);

	job.setReducerClass(CardTotalReducer.class);



	job.setMapOutputKeyClass(Text.class);

	job.setMapOutputValueClass(IntWritable.class);



	job.setOutputKeyClass(Text.class);

	job.setOutputValueClass(IntWritable.class);



	System.exit(job.waitForCompletion(true) ? 0: 1);



}
}
